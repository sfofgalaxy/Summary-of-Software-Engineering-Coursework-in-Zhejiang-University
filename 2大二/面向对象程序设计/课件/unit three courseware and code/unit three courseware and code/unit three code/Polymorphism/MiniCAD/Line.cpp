#include "StdAfx.h"
#include ".\line.h"

#include "mycad.h"
#include "dlgopt.h"
#include <math.h>

IMPLEMENT_SERIAL( CLine, CShape, 1 )

void CLine::Draw(CDC* pDC) 
{
	CPen pen;
	pen.CreatePen(m_nStyle,m_nWidth,m_nColor);
	CPen* sav = pDC->SelectObject(&pen);
	pDC->MoveTo(m_p1);
	pDC->LineTo(m_p2);
	pDC->SelectObject(sav);
	pen.DeleteObject();
}

bool CLine::IsSelected(const CPoint& p) 
{
	int px = m_p2.x - m_p1.x;
	int py = m_p2.y - m_p1.y;
	int x = p.x - m_p1.x;
	int y = p.y - m_p1.y;
	double lineDist = abs(px*y - py*x)/sqrt(double(px*px+py*py));
	if ((lineDist < m_nWidth+5) && (m_p1.x+m_nWidth+5 > p.x && m_p2.x-m_nWidth-5 < p.x || m_p2.x+m_nWidth+5 > p.x && m_p1.x-m_nWidth-5 < p.x) && (m_p1.y+m_nWidth+5 > p.y && m_p2.y-m_nWidth-5 < p.y || m_p2.y+m_nWidth+5 > p.y && m_p1.y-m_nWidth-5 < p.y))
		return true;
	return false;
}

bool CLine::Modify()
{
	CDlgOpt dlg;
	dlg.SetData(m_nStyle,m_nWidth,m_nColor);
	if ( dlg.DoModal() == IDOK ) {
		dlg.GetData(m_nStyle,m_nWidth,m_nColor);
		return true;
	}
	return false;
}

void CLine::Serialize(CArchive& ar)
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
