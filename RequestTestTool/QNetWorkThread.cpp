#include "QNetWorkThread.h"

QNetWorkThread::~QNetWorkThread()
{
	if (SSLStats == false) {
		m_socket.disconnect();
	}
	if (SSLStats == true) {
		m_SSLsocket.disconnect();
	}
}

void QNetWorkThread::SetTimeOut(unsigned int UtimeOut)
{
	TimeOut = UtimeOut * 100;
}

void QNetWorkThread::run()
{//�����Գƣ�����������ifΪʲô��ôд
	emit ThreadSignals(THREAD_START, 0);
	if (EstablishConnection() < 0 ) {
		emit ThreadSignals(THREAD_END, 0);
		return;
	}
	//while (1) {
		if (SendRequestData() < 0 ) {
			emit ThreadSignals(THREAD_END, 0);
			return;
		}
		if (RecvResponseData() < 0) {
			emit ThreadSignals(THREAD_END, 0);
			return;
		}
	//} 
	emit ThreadSignals(THREAD_END, 0);
	return;
}

void QNetWorkThread::NW_Disconnect()
{
	int a = 0;
}

void QNetWorkThread::NW_Error(QAbstractSocket::SocketError socketError)
{
	int a = socketError;
}

void QNetWorkThread::NWSSLError()
{
}

void QNetWorkThread::NW_Encrypted()
{
	isEncryption = true;
}

int QNetWorkThread::EstablishConnection()
{
	if (SSLStats == true) {
		connect(&m_SSLsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(NW_Error(QAbstractSocket::SocketError)), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(disconnected()), this, SLOT(NW_Disconnect()), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(sslErrors()), this, SLOT(NWSSLError()), Qt::DirectConnection);
		connect(&m_SSLsocket, SIGNAL(encrypted()), this, SLOT(NW_Encrypted()), Qt::DirectConnection);

		m_SSLsocket.modeChanged(QSslSocket::SslClientMode);
		m_socket.connectToHost(QString::fromStdString(Host), 443);
		if (!m_socket.waitForConnected(TimeOut)) {
			emit ThreadSignals(THREAD_CONNECT_TIMEOUT, 0); //���ӳ�ʱ
			return -1;
		}
		emit ThreadSignals(THREAD_CONNECT_SUCCESS, 0);
		m_SSLsocket.startClientEncryption();
		if (!m_SSLsocket.waitForEncrypted(TimeOut)) {
			emit ThreadSignals(THREAD_SSL_FALLED, 0);
			m_SSLsocket.disconnect();
			return -2;
		}

		emit ThreadSignals(THREAD_SSL_SUCCESSFUL, 0);
	}
	if (SSLStats == false) {
		connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(NW_Error(QAbstractSocket::SocketError)), Qt::DirectConnection);
		connect(&m_socket, SIGNAL(disconnected()), this, SLOT(NW_Disconnect()), Qt::DirectConnection);

		m_socket.connectToHost(Host.c_str(), Port);
		if (!m_socket.waitForConnected(TimeOut)) {
			emit ThreadSignals(THREAD_CONNECT_TIMEOUT, 0); //���ӳ�ʱ
			return -1;
		}
		emit ThreadSignals(THREAD_CONNECT_SUCCESS, 0);
	}
	return 0;
}

int QNetWorkThread::SendRequestData()
{
	int RequestDataLenth = RequestData.str().length();
	int  SentSuccessfully = 0;
	const char *m_RequestData = RequestData.str().c_str();

	if (SSLStats == true) {
		while (RequestDataLenth - SentSuccessfully > 0) {
			SentSuccessfully = m_SSLsocket.write(m_RequestData + SentSuccessfully, RequestDataLenth - SentSuccessfully);
			if (SentSuccessfully < 0) {
				emit ThreadSignals(THREAD_SEND_FALLED, -1);
				return -1;
			}
			emit ThreadSignals(THREAD_SEND_SUCCESS_COUNT, SentSuccessfully); //���ͼ���
		}
	}
	if (SSLStats == false) {
		while (RequestDataLenth - SentSuccessfully > 0) {
			SentSuccessfully = m_socket.write(m_RequestData + SentSuccessfully, RequestDataLenth - SentSuccessfully);
			if (SentSuccessfully < 0) {
				emit ThreadSignals(THREAD_SEND_FALLED, -1);
				return -1;
			}
			emit ThreadSignals(THREAD_SEND_SUCCESS_COUNT, SentSuccessfully); //���ͼ���
		}
	}
	emit ThreadSignals(THREAD_SEND_SUCCESS, SentSuccessfully); //�������

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

	if (SSLStats == true) {
		
		if (!m_SSLsocket.waitForReadyRead(TimeOut)) {
			emit ThreadSignals(THREAD_RECV_TIMEOUT, 0); //���ճ�ʱ
			return -1;
		}

		while (RecvDataCount) {
			m_Response_Tmp.clear();
			m_Response_Tmp = m_SSLsocket.readAll();
			RecvDataCount = m_Response_Tmp.size();
			m_Response.append(m_Response_Tmp);
			emit ThreadSignals(THREAD_RECV_SUCCESS_COUNT, m_Response.size()); //���ռ���
		}

		ResponseData << m_Response.toStdString();
	}
	if (SSLStats == false) {
		if (!m_socket.waitForReadyRead(TimeOut)) {
			emit ThreadSignals(THREAD_RECV_TIMEOUT, 0); //���ճ�ʱ
			return -1;
		}

		while (RecvDataCount) {
			m_Response_Tmp.clear();
			m_Response_Tmp = m_socket.readAll();
			RecvDataCount = m_Response_Tmp.size();
			m_Response.append(m_Response_Tmp);
			emit ThreadSignals(THREAD_RECV_SUCCESS_COUNT, m_Response.size()); //���ռ���
		}
		ResponseData << m_Response.toStdString();
	}

	emit ThreadSignals(THREAD_RECV_SUCCESS, 0);
	return 0;
}
