#ifndef _PARTICLE_CONTROLLER_INCLUDED_
#define _PARTICLE_CONTROLLER_INCLUDED_

#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "particle.h"
#endif

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif
#include "atoms.h"




class particle_controller
{
public:
	particle_controller(int maxParticles);
	~particle_controller(void);
	int CreateNew(particle::type);
	bool DeleteParticle(int ID);
	void DeleteParticles();
	bool DrawParticle(int ID, HDC bitmapHDC, HDC backHDC);
	bool MoveParticle(int ID, sprite::direction dir);
	void DrawAll(HDC bitmapHDC, HDC backHDC);
	void SetLocation(int ID, int x, int y);
	bool SpaceRemaining();
	bool IsEmpty();
	bool IsParticle(int ID);
	void SetSelected(int ID);
	void DeSelect(int ID) {particles[ID]->SetSelected(false);}
	bool IsSelected(int ID) {return particles[ID]->IsSelected();}
	bool AllParticlesUnselected();
	bool ParticlesInMotion();
	int OnClick(int xClick, int yClick);
	void OnRelease();
	particle::type SelectedParticle(int ID){return particles[ID]->GetType();}

	void SimulateParticles();
	void DetectCompositeParticles();
	void DetectAtoms();
	void DestroyFirstParticleAtMouse();

	void Update(int mouseX, int mouseY);
	void SetScreenSize(int xSize, int ySize);

	int ReportAtomCreation();

private:
	void UpdateAllParticles();
	atom *atomOverlay;
	int atomFrame;
	int maxParticles;
	particle **particles;
	bool *spaces;
	int xSize, ySize;
	int mouseX, mouseY;
	bool gluonPresent;
	int lastAtomCreated;

};

#endif

