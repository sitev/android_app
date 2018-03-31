#include "gameApplication.h"

void android_main(struct android_app* state) {
	GameApplication app(state);
	app.run();
}
