#include "QNetWorkThread.h"

QNetWorkThread::~QNetWorkThread()
{
	if (SSLEnadble == false) {
		m_socket.disconnect();
	}
	if (SSLEnadble == true) {
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

void QNetWorkThread::run()
{
	
	emit ThreadStatusSignals(THREAD_START, 0);
	
	if (EstablishConnection() < 0 ) {
		emit ThreadStatusSignals(THREAD_END, 0);
		return;
	}
	
	while (1) {
		if (SendRequestData() < 0 ) {
			emit ThreadStatusSignals(THREAD_END, 0);
			return;
		}

		if (RecvResponseData() < 0) {
			emit ThreadStatusSignals(THREAD_END, 0);
			return;
		}
		if (WaitForControl(0) == 100) {
			emit ThreadStatusSignals(THREAD_END, 0);
			return;
		}
	} 

	emit ThreadStatusSignals(THREAD_END, 0);
	return;
}

void QNetWorkThread::NW_Connected() {

}
void QNetWorkThread::NW_Disconnect()
{
	emit ThreadStatusSignals(THREAD_CONNECT_TIMEOUT, 0); //连接超时
}

void QNetWorkThread::NW_Error(QAbstractSocket::SocketError socketError)
{
	emit ThreadStatusSignals(THREAD_CONNECT_TIMEOUT, 0); //连接超时
}

void QNetWorkThread::NW_SSLError()
{
	emit ThreadStatusSignals(THREAD_CONNECT_TIMEOUT, 0); //连接超时
}

void QNetWorkThread::NW_Encrypted()
{
	isEncryption = true;
}

int QNetWorkThread::WaitForControl(unsigned int Uststus)
{
	while (1) {
		emit(ThreadContorlSignals(Uststus, &m_ContorlCode));
		if (m_ContorlCode == 0) {
			std::cout << "wait......\n";
			continue;
		}
		if (m_ContorlCode == 100) {
			return 0;//终止
		}
		if (m_ContorlCode == 200) {
			return 1;//继续发送接收
		}
		sleep(1000);
	}
}

int QNetWorkThread::EstablishConnection()
{
	if (SSLEnadble == true) {
		connect(&m_SSLsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(NW_Error(QAbstractSocket::SocketError)), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(disconnected()), this, SLOT(NW_Disconnect()), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(sslErrors()), this, SLOT(NWSSLError()), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(encrypted()), this, SLOT(NW_Encrypted()), Qt::DirectConnection);

		m_SSLsocket.modeChanged(QSslSocket::SslClientMode);
		m_socket.connectToHost(QString::fromStdString(Host), 443);
		if (!m_socket.waitForConnected(TimeOut)) {
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
	if (SSLEnadble == false) {
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

	if (SSLEnadble == true) {
		while (RequestDataLenth - SentSuccessfully > 0) {
			SentSuccessfully = m_SSLsocket.write(m_RequestData + SentSuccessfully, RequestDataLenth - SentSuccessfully);
			if (SentSuccessfully < 0) {
				emit ThreadStatusSignals(THREAD_SEND_FALLED, -1);
				return -1;
			}
			emit ThreadStatusSignals(THREAD_SEND_SUCCESS_COUNT, SentSuccessfully); //发送计数
		}
	}
	if (SSLEnadble == false) {
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

	if (SSLEnadble == true) {
		
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
	if (SSLEnadble == false) {
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
