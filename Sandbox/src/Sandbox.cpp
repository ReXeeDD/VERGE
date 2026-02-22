#include"Verge.h"

class Sandbox :public Verge::Application {

public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Verge::Application* Verge::CreateApplication (){
	return new Sandbox();

}