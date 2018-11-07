#include "ActionManager.h"

//Needs an input event as a parameter
void ActionManager::HandleInput(SDL_Event _event, Character* _unit) {

	/* ---- Movement Input ---- */
	{
		if (_event.key.keysym.sym == SDLK_w) {
			//float newY = _unit->getY + 1.0f;
			Vec2 * newPos = new Vec2(_unit->getPosition()->x, _unit->getPosition()->y - 10.0f);
			Undoer->AddCommand(new Move(_unit, newPos));
		}

		else if (_event.key.keysym.sym == SDLK_s) {
			//float newY = _unit->getY - 1.0f;
			Vec2 * newPos = new Vec2(_unit->getPosition()->x, _unit->getPosition()->y + 10.0f);
			Undoer->AddCommand(new Move(_unit, newPos));
		}

		else if (_event.key.keysym.sym == SDLK_a) {
			//float newX = _unit->getX - 1.0f;
			Vec2 * newPos = new Vec2(_unit->getPosition()->x - 10.0f, _unit->getPosition()->y);
			Undoer->AddCommand(new Move(_unit, newPos));
		}

		else if (_event.key.keysym.sym == SDLK_d) {
			//float newX = _unit->getX + 1.0f;
			Vec2 * newPos = new Vec2(_unit->getPosition()->x + 10.0f, _unit->getPosition()->y);
			Undoer->AddCommand(new Move(_unit, newPos));
		}

	}
	/* ---- End of Movement Input ---- */

	/* ---- Health Input ---- */
	{
		if (_event.key.keysym.sym == SDLK_UP) {
			if (_unit->getHealth() < 100) {
				Undoer->AddCommand(new AddHealth(_unit, 1));
			}
		}

		else if (_event.key.keysym.sym == SDLK_DOWN) {
			if (_unit->getHealth() > 0) {
				Undoer->AddCommand(new AddHealth(_unit, -1));
			}
		}
	}
	/* ---- End of Health Input ---- */

	/* ---- Money Input ---- */
	{
		if (_event.type == SDL_KEYUP) {
	
			if (_event.key.keysym.sym == SDLK_p) {
				if (_unit->walletBalance() >= 1.50f) {
					Undoer->AddCommand(new Purchase(_unit, 1.50));
				}
			}

		}
	}
	/* ---- End of Money Input ---- */

	/* ---- UNDO ---- */
	if (_event.key.keysym.sym == SDLK_z) {
		if (Undoer->hasActions())
			Undoer->UndoCommand();
	}


}

ActionManager::ActionManager() {
	Undoer = new UndoManager();
}


ActionManager::~ActionManager() {
}
