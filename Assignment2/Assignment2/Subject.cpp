#include "Subject.h"



Subject::Subject()
{
	head = nullptr;
}


Subject::~Subject()
{
}

void Subject::addObserver(Observer * observer) {
	observer->next = head;
	head = observer;
}

void Subject::removeObserver(Observer * observer) {
	if (head == observer)
	{
		head = observer->next;
		observer->next = nullptr;
		return;
	}

	Observer* current = head;
	while (current != nullptr)
	{
		if (current->next == observer)
		{
			current->next = observer->next;
			observer->next = nullptr;
			return;
		}

		current = current->next;
	}
}

void Subject::notify(const Entity * entity, SDL_Event event) {
	Observer* observer = head;
	while (observer != nullptr)
	{
		observer->onNotify(entity, event);
		observer = observer->next;
	}

}
