#include "StdAfx.h"
#include ".\rectangle.h"

#include "mycad.h"
#include "dlgopt.h"

IMPLEMENT_SERIAL( CRectangle, CShape, 1 )

void CRectangle::Draw(CDC* pDC) 
{
	CPen pen;
	pen.CreatePen(m_nStyle,m_nWidth,RGB(0,0,0));
	CPen* sav = pDC->SelectObject(&pen);

	CBrush brush(m_nColor);
	CBrush* oldBrush = pDC->SelectObject(&brush);


	CRect rect = GetRect();
	pDC->MoveTo(m_p1);
	pDC->Rectangle(rect);

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(sav);
	pen.DeleteObject();
}

bool CRectangle::IsSelected(const CPoint& p) 
{
	if ((m_p1.x+m_nWidth+5 > p.x && m_p2.x-m_nWidth-5 < p.x || m_p2.x+m_nWidth+5 > p.x && m_p1.x-m_nWidth-5 < p.x) && (m_p1.y+m_nWidth+5 > p.y && m_p2.y-m_nWidth-5 < p.y || m_p2.y+m_nWidth+5 > p.y && m_p1.y-m_nWidth-5 < p.y))
		return true;
	else
		return false;
}

bool CRectangle::Modify()
{
	CDlgOpt dlg;
	dlg.SetData(m_nStyle,m_nWidth,m_nColor);
	if ( dlg.DoModal() == IDOK ) {
		dlg.GetData(m_nStyle,m_nWidth,m_nColor);
		return true;
	}
	return false;
}

void CRectangle::Serialize(CArchive& ar)
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
