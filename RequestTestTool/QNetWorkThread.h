#pragma once

#define THREAD_START 100
#define THREAD_CONNECT_SUCCESS 1021
#define THREAD_CONNECT_TIMEOUT 102
#define THREAD_SEND_SUCCESS_COUNT 103
#define THREAD_SEND_SUCCESS 104
#define THREAD_SEND_TIMEOUT 105
#define THREAD_SEND_FALLED 2324
#define THREAD_RECV_SUCCESS_COUNT 106
#define THREAD_RECV_SUCCESS 107
#define THREAD_RECV_TIMEOUT 108
#define THREAD_CONNECTED 109
#define THREAD_END 110

#define THREAD_SSL_SUCCESSFUL 111
#define THREAD_SSL_FALLED 112

#define THREAD_CONTROL_CONTINUE 8978;
#define THREAD_CONTROL_STOP 8975;
#define THREAD_CONTROL_NEXT 89348;

#include <QThread>
#include <qtcpsocket.h>
#include <qsslsocket.h>
#include <QThread>

#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>

class QNetWorkThread : public QThread
{
	Q_OBJECT

signals :
	void ThreadStatusSignals(unsigned int Uststus, unsigned int UDatasize);
	/*
	100 �߳̿�ʼ
	400 ���Ӵ���
	500 ������״̬
	600 ��ȡ��״̬
	700 �߳̽���
	*/
	void ThreadContorlSignals(unsigned int Uststus,unsigned int *UContorl);
public:
	QNetWorkThread() = delete;
	QNetWorkThread(QNetWorkThread &) = delete;
	QNetWorkThread(std::string UHost, unsigned int UPort, bool USSLEnadble, std::stringstream &URequestData, std::stringstream &UResponseData)
		:Host(UHost), Port(UPort), RequestData(URequestData), ResponseData(UResponseData), SSLEnadble(USSLEnadble) {
		TimeOut = 5000;
		isEncryption = false;
	};
	/*
	UHost : ��ַ
	UPort : �˿�
	USSLStatus : �Ƿ���SSL
	URequestData : ��Ҫ���͵�����
	UResponse : ��������
	*/
	~QNetWorkThread();
	void SetTimeOut(unsigned int UtimeOut);
	void SetKeepAlive(bool Ubool);//�Ƿ����ó�����

	void run();
public slots:
	void NW_Connected();//���ӳɹ�
	void NW_Disconnect();//���ӶϿ�
	void NW_Error(QAbstractSocket::SocketError socketError);//��������
	void NW_SSLError();//SSL����
	void NW_Encrypted();//SSL���ֳɹ�
private:
	unsigned int m_ContorlCode = 0;
	int WaitForControl(unsigned int Uststus);
	int EstablishConnection();
	int SendRequestData();
	int RecvResponseData();
	unsigned int TimeOut;
	int IRecvCout;
	std::string Host;
	unsigned int Port;
	bool once;
	bool SSLEnadble;
	bool isEncryption;
	bool IsKeepAlive;
	std::stringstream &RequestData; //��������
	std::stringstream &ResponseData;//��Ӧ����

	QSslSocket m_SSLsocket;
	QTcpSocket m_socket;
};
