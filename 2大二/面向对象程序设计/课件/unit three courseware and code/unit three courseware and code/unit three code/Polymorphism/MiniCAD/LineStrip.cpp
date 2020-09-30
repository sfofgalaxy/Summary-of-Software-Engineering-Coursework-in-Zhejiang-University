#include "StdAfx.h"
#include ".\LineStrip.h"

#include "mycad.h"
#include "dlgopt.h"

IMPLEMENT_SERIAL( CLineStrip, CShape, 1 )

void CLineStrip::Draw(CDC* pDC) 
{
	if (points != NULL) {
		CPen pen;
		pen.CreatePen(m_nStyle,m_nWidth,m_nColor);
		CPen* sav = pDC->SelectObject(&pen);
		pDC->Polyline(points,num);
		/*
		pDC->MoveTo(points[0]);
		for (int i=1 ;i<num; ++i) {
			pDC->LineTo(points[i]);
		}
		*/
		pDC->SelectObject(sav);
		pen.DeleteObject();
	}
}

bool CLineStrip::IsSelected(const CPoint& p) 
{
	CPoint p1 = points[0], p2;
	for (int i=1; i<num; ++i) {
		p2 = points[i];

		int px = p2.x - p1.x;
		int py = p2.y - p1.y;
		int x = p.x - p1.x;
		int y = p.y - p1.y;
		double lineDist = abs(px*y - py*x)/sqrt(double(px*px+py*py));
		if ((lineDist < m_nWidth+5) && (p1.x+m_nWidth+5 > p.x && p2.x-m_nWidth-5 < p.x || p2.x+m_nWidth+5 > p.x && p1.x-m_nWidth-5 < p.x) && (p1.y+m_nWidth+5 > p.y && p2.y-m_nWidth-5 < p.y || p2.y+m_nWidth+5 > p.y && p1.y-m_nWidth-5 < p.y))
			return true;

		p1=p2;
	}
	return false;

}

bool CLineStrip::Modify()
{
	CDlgOpt dlg;
	dlg.SetData(m_nStyle,m_nWidth,m_nColor);
	if ( dlg.DoModal() == IDOK ) {
		dlg.GetData(m_nStyle,m_nWidth,m_nColor);
		return true;
	}
	return false;
}

void CLineStrip::Serialize(CArchive& ar)
{
	CShape::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		ar << num;
		for (int i=0; i<num; ++i) {
			ar << points[i];
		}
		ar << m_p1 << m_p2 << m_nStyle << m_nWidth;
	}
	else
	{	// loading code
		ar >> num;
		points = new CPoint[num];
		for (int i=0; i<num; ++i) {
			ar >> points[i];
		}
		ar >> m_p1 >> m_p2 >> m_nStyle >> m_nWidth;
	}
}
