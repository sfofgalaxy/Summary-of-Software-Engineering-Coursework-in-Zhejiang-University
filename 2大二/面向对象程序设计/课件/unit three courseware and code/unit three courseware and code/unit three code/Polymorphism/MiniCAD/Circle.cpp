#include "StdAfx.h"
#include ".\circle.h"

#include "mycad.h"
#include "dlgopt.h"
#include <math.h>

IMPLEMENT_SERIAL( CCircle, CShape, 1 )

void CCircle::Draw(CDC* pDC) 
{
	CPen pen;
	pen.CreatePen(m_nStyle,m_nWidth,RGB(0,0,0));
	CPen* sav = pDC->SelectObject(&pen);

	CBrush brush(m_nColor);
	CBrush* oldBrush = pDC->SelectObject(&brush);


	CRect rect = GetRect();
	pDC->MoveTo(m_p1);
	pDC->Ellipse(rect);

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(sav);
	pen.DeleteObject();
}

bool CCircle::IsSelected(const CPoint& p) 
{
	CPoint center((m_p1.x + m_p2.x)/2,(m_p1.y + m_p2.y)/2);
	int xRad = abs(m_p1.x-m_p2.x)/2+3;
	int yRad = abs(m_p1.y-m_p2.y)/2+3;
	if (1.0*(p.x-center.x)*(p.x-center.x)/(xRad*xRad) + 1.0*(p.y-center.y)*(p.y-center.y)/(yRad*yRad) <= 1)
		return true;
	else
		return false;
}

bool CCircle::Modify()
{
	CDlgOpt dlg;
	dlg.SetData(m_nStyle,m_nWidth,m_nColor);
	if ( dlg.DoModal() == IDOK ) {
		dlg.GetData(m_nStyle,m_nWidth,m_nColor);
		return true;
	}
	return false;
}

void CCircle::Serialize(CArchive& ar)
{
	CShape::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar << m_p1 << m_p2 << m_nStyle << m_nWidth;
	}
	else
	{	// loading code
		ar >> m_p1 >> m_p2 >> m_nStyle >> m_nWidth;
	}
}
