
#include "PELCO_D.h"


bool PELCO_D::Init(int com)
{
	char name[20];
	sprintf(name,"COM%d",com);
	bool result = comm.open(name,CBR_2400,NOPARITY,ONESTOPBIT,8);
	return result;
}

void PELCO_D::Up()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x00,0x08,0x00,0xff,0x08,}//��
		BYTE code[7] = {0xff,0x01,0x00,0x08,0x00,0xff,0x08};
		comm.output(code,7);
	}
}

void PELCO_D::Down()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x00,0x10,0x00,0xff,0x10,}//��
		BYTE code[7] = {0xff,0x01,0x00,0x10,0x00,0xff,0x10};
		comm.output(code,7);
	}
}

void PELCO_D::Stop()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x00,0x00,0x00,0x00,0x01,}//ͣ����
		BYTE code[7] = {0xff,0x01,0x00,0x00,0x00,0x00,0x01};
		comm.output(code,7);
	}
}

void PELCO_D::Right()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x00,0x02,0xff,0x00,0x02,}//��
		BYTE code[7] = {0xff,0x01,0x00,0x02,0xff,0x00,0x02};
		comm.output(code,7);
	}
}

void PELCO_D::Left()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x00,0x04,0xff,0x00,0x04,}//��
		BYTE code[7] = {0xff,0x01,0x00,0x04,0xff,0x00,0x04};
		comm.output(code,7);
	}
}

void PELCO_D::FocusNear()
{
	if (comm.isAvailable())
	{

		//{0xff,0x01,0x00,0x80,0x00,0x00,0x81,}//�۽���
		BYTE code[7] ={0xff,0x01,0x00,0x80,0x00,0x00,0x81};
		comm.output(code,7);
	}
}

void PELCO_D::FocusFar()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x01,0x00,0x00,0x00,0x02,}//�۽�Զ
		BYTE code[7] = {0xff,0x01,0x01,0x00,0x00,0x00,0x02};
		comm.output(code,7);
	}
}

void PELCO_D::ZoomOut()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x00,0x40,0x00,0x00,0x41,}//�䱶��
		BYTE code[7] ={0xff,0x01,0x00,0x40,0x00,0x00,0x41};
		comm.output(code,7);
	}
}

void PELCO_D::ZoomIn()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x00,0x20,0x00,0x00,0x21,}//�䱶��
		BYTE code[7] = {0xff,0x01,0x00,0x20,0x00,0x00,0x21};
		comm.output(code,7);
	}
}

void PELCO_D::ApertureLarge()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x04,0x00,0x00,0x00,0x05,}//��Ȧ��
		BYTE code[7] = {0xff,0x01,0x04,0x00,0x00,0x00,0x05};
		comm.output(code,7);
	}
}

void PELCO_D::ApertureSmall()
{
	if (comm.isAvailable())
	{
		//{0xff,0x01,0x02,0x00,0x00,0x00,0x03,}//��ȦС
		BYTE code[7] = {0xff,0x01,0x02,0x00,0x00,0x00,0x03};
		comm.output(code,7);
	}
}

bool PELCO_D::Available()
{
	return comm.isAvailable();
}

void PELCO_D::SetSpeed( int speed )
{
	//speed range from 00H to 3FH(63)
	this->speed = speed>63?63:(speed<0?0:speed);
}

int PELCO_D::GetSpeed()
{
	return this->speed;
}
