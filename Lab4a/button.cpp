#include "button.h"
#include "particle.h"


button::button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName, int x, int y):
	background(szBGFileName, x, y),
	mouseover(szMOFileName, x, y),
	image(szImgFileName, x, y),
	mOver(false)
{
}

button::button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName):
	background(szBGFileName),
	mouseover(szMOFileName),
	image(szImgFileName),
	mOver(false)
{
}

button::button(particle::type ParticleType):
	background("button3.bmp"),
	mouseover("button4.bmp")
{
	SetNew(ParticleType);
}

void button::SetNew(particle::type ParticleType)
{
	particleType = ParticleType;
	switch (ParticleType) {
		case particle::NONE:
			break;
		case  particle::UP_QUARK:
			image.SetSprite("imgupq.bmp");
			break;
		case  particle::DOWN_QUARK:
			image.SetSprite("imgdwq.bmp");
			break;
		case  particle::TOP_QUARK:
			image.SetSprite("imgtpq.bmp");
			break;
		case  particle::BOTTOM_QUARK:
			image.SetSprite("imgbtq.bmp");
			break;
		case  particle::STRANGE_QUARK:
			image.SetSprite("imgstrq.bmp");
			break;
		case  particle::CHARM_QUARK:
			image.SetSprite("imgchq.bmp");
			break;
		case  particle::GLUON:
			image.SetSprite("imggluon.bmp");
			break;
		case  particle::ELECTRON:
			image.SetSprite("imgelec.bmp");
			break;
		case  particle::PROTON:
			image.SetSprite("imgprtn.bmp");
			break;
		case  particle::NEUTRON:
			image.SetSprite("imgntrn.bmp");
			break;
	}
}


button::~button(void)
{
}

void button::Update(int x, int y)
{
	if (background.MouseOver(x, y) || mouseover.MouseOver(x, y))
		mOver = true;
	else
		mOver = false;
}

bool button::OnClick(int x, int y)
{
	if (background.OnClick(x, y) || mouseover.OnClick(x, y)){
		selected = true;
		return (true);
	} else {
		selected = false;
		return (false);
	}
}

void button::Draw(HDC bitmapHDC, HDC backHDC)
{
	if(mOver)
		mouseover.Draw(bitmapHDC, backHDC);
	else
		background.Draw(bitmapHDC, backHDC);

	image.Draw(bitmapHDC, backHDC);
}