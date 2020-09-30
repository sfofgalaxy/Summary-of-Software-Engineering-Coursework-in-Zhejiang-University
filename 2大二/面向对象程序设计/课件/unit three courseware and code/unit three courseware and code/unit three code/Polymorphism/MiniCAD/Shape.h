#pragma once



// CShape command target

#include <atltypes.h>	//	for CPoint & CRect

class CShape : public CObject
{
public:
	DECLARE_SERIAL( CShape )

	CShape():m_nColor(RGB(0,0,0)) {};
	virtual ~CShape() {};

	//	Draw the shape on pDC with attributes
	virtual void Draw(CDC* pDC) {};
	//	Resize the shape with the current mouse location p
	virtual void Resize(const CPoint& p) {};
	//	Return true if p in on the shape
	virtual bool IsSelected(const CPoint& p) { return false; };
	//	Move shape with dx,dy
	virtual void Move(int dx, int dy) {};
	//	Modify attributes
	virtual bool Modify() { return false; };
	//	Clone the shape
	virtual CShape* Clone() { return 0; };
	//	Return the min surrounding rectangle
	virtual CRect GetRect() { return CRect(0,0,0,0); };
protected:
	COLORREF m_nColor;
public:
	virtual void Serialize(CArchive& ar);
};
