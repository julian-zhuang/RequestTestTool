#include "QNetWorkThread.h"

QNetWorkThread::~QNetWorkThread()
{
	if (SSL_Enadble == false) {
		m_socket.disconnect();
	}
	if (SSL_Enadble == true) {
		m_SSLsocket.disconnect();
	}
}

void QNetWorkThread::SetTimeOut(unsigned int UtimeOut)
{
	TimeOut = UtimeOut * 100;
}

void QNetWorkThread::SetKeepAlive(bool Ubool)
{
	IsKeepAlive = Ubool;
}

void QNetWorkThread::SetThreadControlSignal(unsigned int UCOntorl)
{
	m_ControlSignal = UCOntorl;
}

void QNetWorkThread::run()
{
	
	//发出线程开始的信号
	emit ThreadStatusSignals(THREAD_START, 0);
	
	//建立连接
	if (EstablishConnection() < 0 ) {
		emit ThreadStatusSignals(THREAD_END, 0);
		return;
	}
	
	//循环发送和读取
	bool flag = true;
	while (flag) {
		if (SendRequestData() < 0 ) {
			emit ThreadStatusSignals(THREAD_END, 0);
			return;
		}

		if (RecvResponseData() < 0) {
			emit ThreadStatusSignals(THREAD_END, 0);
			return;
		}
		//一次发送接收完成，阻塞等待
		switch (WaitControlSignal())
		{
		case THREAD_CONTROL_CONTINUE:
			break;
		case THREAD_CONTROL_STOP:
			flag = false;
			break;
		default:
			flag = false;
			break;
		}
	} 

	emit ThreadStatusSignals(THREAD_END, 0);
	return;
}

void QNetWorkThread::NW_Disconnect()
{
	emit ThreadStatusSignals(THREAD_CONNECTED, 0); //连接超时
}

void QNetWorkThread::NW_Error(QAbstractSocket::SocketError socketError)
{
	int a = socketError;
	int b = 0;
}

void QNetWorkThread::NW_SSLError()
{
	m_ControlSignal = THREAD_CONTROL_STOP;
}

void QNetWorkThread::NW_Encrypted()
{
	isEncryption = true;
}

unsigned int QNetWorkThread::WaitControlSignal()
{
	if (IsKeepAlive == false) {
		return THREAD_CONTROL_STOP;
	}
	while (1)
	{
		if (m_ControlSignal == THREAD_CONTROL_STOP) {
			m_ControlSignal = 0;
			return THREAD_CONTROL_STOP;
		}
		if (m_ControlSignal == THREAD_CONTROL_CONTINUE) {
			m_ControlSignal = 0;
			return THREAD_CONTROL_CONTINUE;
		}
		usleep(1);//切换CPU时间片
	}
	return 0;
}

int QNetWorkThread::EstablishConnection()
{
	if (SSL_Enadble == true) {
		connect(&m_SSLsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(NW_Error(QAbstractSocket::SocketError)), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(disconnected()), this, SLOT(NW_Disconnect()), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(sslErrors()), this, SLOT(NW_SSLError()), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(encrypted()), this, SLOT(NW_Encrypted()), Qt::DirectConnection);

		m_SSLsocket.modeChanged(QSslSocket::SslClientMode);
		m_SSLsocket.connectToHost(QString::fromStdString(Host), Port);
		if (!m_SSLsocket.waitForConnected(TimeOut)) {
			emit ThreadStatusSignals(THREAD_CONNECT_TIMEOUT, 0); //连接超时
			return -1;
		}
		emit ThreadStatusSignals(THREAD_CONNECT_SUCCESS, 0);
		m_SSLsocket.startClientEncryption();
		if (!m_SSLsocket.waitForEncrypted(TimeOut)) {
			emit ThreadStatusSignals(THREAD_SSL_FALLED, 0);
			m_SSLsocket.disconnect();
			return -2;
		}
		emit ThreadStatusSignals(THREAD_SSL_SUCCESSFUL, 0);
	}
	if (SSL_Enadble == false) {
		connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(NW_Error(QAbstractSocket::SocketError)), Qt::DirectConnection);
		connect(&m_socket, SIGNAL(disconnected()), this, SLOT(NW_Disconnect()), Qt::DirectConnection);

		m_socket.connectToHost(Host.c_str(), Port);
		if (!m_socket.waitForConnected(TimeOut)) {
			emit ThreadStatusSignals(THREAD_CONNECT_TIMEOUT, 0); //连接超时
			return -1;
		}
		emit ThreadStatusSignals(THREAD_CONNECT_SUCCESS, 0);
	}
	return 0;
}

int QNetWorkThread::SendRequestData()
{
	int RequestDataLenth = RequestData.str().length();
	int  SentSuccessfully = 0;
	const char *m_RequestData = RequestData.str().c_str();

	if (SSL_Enadble == true) {
		while (RequestDataLenth - SentSuccessfully > 0) {
			SentSuccessfully = m_SSLsocket.write(m_RequestData + SentSuccessfully, RequestDataLenth - SentSuccessfully);
			if (SentSuccessfully < 0) {
				emit ThreadStatusSignals(THREAD_SEND_FALLED, -1);
				return -1;
			}
			emit ThreadStatusSignals(THREAD_SEND_SUCCESS_COUNT, SentSuccessfully); //发送计数
		}
	}
	if (SSL_Enadble == false) {
		while (RequestDataLenth - SentSuccessfully > 0) {
			SentSuccessfully = m_socket.write(m_RequestData + SentSuccessfully, RequestDataLenth - SentSuccessfully);
			if (SentSuccessfully < 0) {
				emit ThreadStatusSignals(THREAD_SEND_FALLED, -1);
				return -1;
			}
			emit ThreadStatusSignals(THREAD_SEND_SUCCESS_COUNT, SentSuccessfully); //发送计数
		}
	}
	emit ThreadStatusSignals(THREAD_SEND_SUCCESS, SentSuccessfully); //发送完成

	return 0;
}

int QNetWorkThread::RecvResponseData()
{
	QByteArray m_Response;
	QByteArray m_Response_Tmp;
	ResponseData.clear();
	ResponseData.str("");
	
	m_Response.clear();
	m_Response_Tmp.clear();
	int RecvDataCount = 1;

	if (SSL_Enadble == true) {
		
		if (!m_SSLsocket.waitForReadyRead(TimeOut)) {
			emit ThreadStatusSignals(THREAD_RECV_TIMEOUT, 0); //接收超时
			return -1;
		}

		while (RecvDataCount) {
			m_Response_Tmp.clear();
			m_Response_Tmp = m_SSLsocket.readAll();
			RecvDataCount = m_Response_Tmp.size();
			m_Response.append(m_Response_Tmp);
			emit ThreadStatusSignals(THREAD_RECV_SUCCESS_COUNT, m_Response.size()); //接收计数
		}

		ResponseData << m_Response.toStdString();
	}
	if (SSL_Enadble == false) {
		if (!m_socket.waitForReadyRead(TimeOut)) {
			emit ThreadStatusSignals(THREAD_RECV_TIMEOUT, 0); //接收超时
			return -1;
		}

		while (RecvDataCount) {
			m_Response_Tmp.clear();
			m_Response_Tmp = m_socket.readAll();
			RecvDataCount = m_Response_Tmp.size();
			m_Response.append(m_Response_Tmp);
			emit ThreadStatusSignals(THREAD_RECV_SUCCESS_COUNT, m_Response.size()); //接收计数
		}
		ResponseData << m_Response.toStdString();
	}

	emit ThreadStatusSignals(THREAD_RECV_SUCCESS, 0);
	return 0;
}
