// NewsInfo.h: interface for the CNewsInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEWSINFO_H__777B8CA2_3E6F_4AA9_B0BE_9975500B61BC__INCLUDED_)
#define AFX_NEWSINFO_H__777B8CA2_3E6F_4AA9_B0BE_9975500B61BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<fstream>
using namespace std;

class CNewsInfo  
{
public:
	CString title;
	CString time;
	CString addr;
	CString web;
	CNewsInfo();
	virtual ~CNewsInfo();
	CString GetURL()
	{
		//UpdateData();
		CInternetSession sess;//�����Ự
		CHttpFile* pF=(CHttpFile*)sess.OpenURL(addr);//���ļ�
		CString szData,szAllData,m_szHTML;
		while(pF->ReadString(szData)){//��ȡ�ļ�
			szAllData+="\r\n";
			szAllData+=szData;
		}
		pF->Close();
		sess.Close();
		m_szHTML=szAllData;
		return m_szHTML;
		//UpdateData(FALSE);
	}

//	CString deal1(CString data);//deal 1��2 ��������ȡ����ҳ�������ݵĺ���
//	CString deal2(CString data);
};

#endif // !defined(AFX_NEWSINFO_H__777B8CA2_3E6F_4AA9_B0BE_9975500B61BC__INCLUDED_)
