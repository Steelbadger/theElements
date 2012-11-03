#include "gameUI.h"


gameUI::gameUI(int w, int h):
	bottomMenu("UIBottom.bmp"),
	upQuark("button3.bmp", "button4.bmp", "imgupq.bmp"),
	downQuark("button3.bmp", "button4.bmp", "imgdwq.bmp"),
	topQuark("button3.bmp", "button4.bmp", "imgtpq.bmp"),
	bottomQuark("button3.bmp", "button4.bmp", "imgbtq.bmp"),
	charmQuark("button3.bmp", "button4.bmp", "imgchq.bmp"),
	strangeQuark("button3.bmp", "button4.bmp", "imgstrq.bmp"),
	gluon("button3.bmp", "button4.bmp", "imggluon.bmp")
{
	width = w;
	height = h;
	bottomMenu.SetLocation((w-bottomMenu.GetWidth())/2, h - 20);
	upQuark.SetLocation(bottomMenu.GetX() + 34, bottomMenu.GetY() - 10);
	downQuark.SetLocation(bottomMenu.GetX() + 115, bottomMenu.GetY() - 10);
	topQuark.SetLocation(bottomMenu.GetX() + 196, bottomMenu.GetY() - 10);
	bottomQuark.SetLocation(bottomMenu.GetX() + 277, bottomMenu.GetY() - 10);
	charmQuark.SetLocation(bottomMenu.GetX() + 358, bottomMenu.GetY() - 10);
	strangeQuark.SetLocation(bottomMenu.GetX() + 439, bottomMenu.GetY() - 10);
	gluon.SetLocation(bottomMenu.GetX() + 520, bottomMenu.GetY() - 10);
}


gameUI::~gameUI(void)
{
}

void gameUI::Display(HDC bitmapHDC, HDC backHDC)
{
	bottomMenu.Draw(bitmapHDC, backHDC);
	upQuark.Draw(bitmapHDC, backHDC);
	downQuark.Draw(bitmapHDC, backHDC);
	topQuark.Draw(bitmapHDC, backHDC);
	bottomQuark.Draw(bitmapHDC, backHDC);
	charmQuark.Draw(bitmapHDC, backHDC);
	strangeQuark.Draw(bitmapHDC, backHDC);
	gluon.Draw(bitmapHDC, backHDC);
}

void gameUI::Update(int x, int y)
{
	SetMouseLoc(x, y);
	upQuark.Update(x,y);
	downQuark.Update(x,y);
	topQuark.Update(x,y);
	bottomQuark.Update(x,y);
	charmQuark.Update(x,y);
	strangeQuark.Update(x,y);
	gluon.Update(x,y);
	if (bottomMenu.MouseOver(mouseX, mouseY)){
		if (bottomMenu.GetY() > (height - 100)){
			bottomMenu.Move(sprite::UP);
			upQuark.Move(sprite::UP);
			downQuark.Move(sprite::UP);
			topQuark.Move(sprite::UP);
			bottomQuark.Move(sprite::UP);
			charmQuark.Move(sprite::UP);
			strangeQuark.Move(sprite::UP);
			gluon.Move(sprite::UP);
		}
	} else if (bottomMenu.GetY() < (height - 20)){
		bottomMenu.Move(sprite::DOWN);
		upQuark.Move(sprite::DOWN);
		downQuark.Move(sprite::DOWN);
		topQuark.Move(sprite::DOWN);
		bottomQuark.Move(sprite::DOWN);
		charmQuark.Move(sprite::DOWN);
		strangeQuark.Move(sprite::DOWN);
		gluon.Move(sprite::DOWN);
	}
		
}
void gameUI::SetDisplaySize(int w, int h)
{
	width = w;
	height = h;
	bottomMenu.SetLocation((w-bottomMenu.GetWidth())/2, h - 20);
	upQuark.SetLocation(bottomMenu.GetX() + 34, bottomMenu.GetY() + 27);
	downQuark.SetLocation(bottomMenu.GetX() + 115, bottomMenu.GetY() + 27);
	topQuark.SetLocation(bottomMenu.GetX() + 196, bottomMenu.GetY() + 27);
	bottomQuark.SetLocation(bottomMenu.GetX() + 277, bottomMenu.GetY() + 27);
	charmQuark.SetLocation(bottomMenu.GetX() + 358, bottomMenu.GetY() + 27);
	strangeQuark.SetLocation(bottomMenu.GetX() + 439, bottomMenu.GetY() + 27);
	gluon.SetLocation(bottomMenu.GetX() + 520, bottomMenu.GetY() + 27);
}

particle::type gameUI::ReturnParticleCreation()
{
	if (upQuark.OnClick(mouseX, mouseY))
		return particle::UP_QUARK;
	else if (downQuark.OnClick(mouseX, mouseY))
		return particle::DOWN_QUARK;
	else if (topQuark.OnClick(mouseX, mouseY))
		return particle::TOP_QUARK;
	else if (bottomQuark.OnClick(mouseX, mouseY))
		return particle::BOTTOM_QUARK;
	else if (charmQuark.OnClick(mouseX, mouseY))
		return particle::CHARM_QUARK;
	else if (strangeQuark.OnClick(mouseX, mouseY))
		return particle::STRANGE_QUARK;
	else if (gluon.OnClick(mouseX, mouseY))
		return particle::GLUON;
	else
		return particle::NONE;
}