#include "gameUI.h"


gameUI::gameUI(int w, int h):
	bottomMenu("UIBottom.bmp"),
	tableButton("tableButton.bmp", "tableButtonMO.bmp", "tableButtonImg.bmp", 0,0),
	lockIcon("UIBottomlock.bmp")
{
	width = w;
	height = h;
	buttons[0] = new button(particle::UP_QUARK);
	buttons[1] = new button(particle::DOWN_QUARK);
	buttons[2] = new button(particle::GLUON);
	buttons[3] = new button(particle::ELECTRON);
	bottomMenuLock = false;
	for (int i = 4; i < 7; i++) {
		buttons[i] = new button(particle::NONE);
	}


	for (int i = 0; i < 7; i++) {
		buttons[i]->SetLocation(bottomMenu.GetX() + 34 + 81*i, bottomMenu.GetY() - 10);
	}
}


gameUI::~gameUI(void)
{
}

void gameUI::Display(HDC bitmapHDC, HDC backHDC)
{
	bottomMenu.Draw(bitmapHDC, backHDC);
	for (int i = 0; i < 7; i++) {
		buttons[i]->Draw(bitmapHDC, backHDC);
	}
	tableButton.Draw(bitmapHDC, backHDC);
	if (lockIcon.MouseOver(mouseX, mouseY) || bottomMenuLock == true) {
		lockIcon.Draw(bitmapHDC, backHDC);
	}
}

void gameUI::Update(int x, int y)
{
	SetMouseLoc(x, y);
	for (int i = 0; i < 7; i++) {
		buttons[i]->Update(x, y);
	}
	tableButton.Update(x, y);

	if (bottomMenu.MouseOver(mouseX, mouseY) || bottomMenuLock == true){
		if (bottomMenu.GetY() > (height - 100)){
			bottomMenu.Move(sprite::UP);
			lockIcon.Move(sprite::UP);
			for (int i = 0; i < 7; i++) {
				buttons[i]->Move(sprite::UP);
			}
		}
	} else if (bottomMenu.GetY() < (height - 20)){
		bottomMenu.Move(sprite::DOWN);
		lockIcon.Move(sprite::DOWN);
		for (int i = 0; i < 7; i++) {
			buttons[i]->Move(sprite::DOWN);
		}
	}
		
}
void gameUI::SetDisplaySize(int w, int h)
{
	width = w;
	height = h;
	bottomMenu.SetLocation((w-bottomMenu.GetWidth())/2, h - 20);
	lockIcon.SetLocation((w-lockIcon.GetWidth())/2, h - 15);
	for (int i = 0; i < 7; i++) {
		buttons[i]->SetLocation(bottomMenu.GetX() + 34 + 81*i, bottomMenu.GetY() + 27);
	}
}

particle::type gameUI::ReturnParticleCreation()
{
	for (int i = 0; i < 7; i++) {
		if (buttons[i]->OnClick(mouseX, mouseY)){
			return buttons[i]->CreateParticle();
		}
	}
	return particle::NONE;
}
bool gameUI::OnTableClick()
{
	if (tableButton.OnClick(mouseX, mouseY)){
		return true;
	}
	return false;
}

void gameUI::OnClick()
{
	if (lockIcon.MouseOver(mouseX, mouseY))
		bottomMenuLock = !bottomMenuLock;
}

bool gameUI::OnMouseRelease(particle::type p)
{
	for (int i = 0; i < 7; i++) {
		if (buttons[i]->MouseOver(mouseX, mouseY) && buttons[i]->CreateParticle() == particle::NONE){
			buttons[i]->SetNew(p);
			return true;
		}
	}
	return false;

}