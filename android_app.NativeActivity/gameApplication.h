#pragma once

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "AndroidProject1.NativeActivity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "AndroidProject1.NativeActivity", __VA_ARGS__))

/**
* Наши сохраненные данные состояния.
*/
struct SavedState {
	float angle;
	int32_t x;
	int32_t y;
};

/**
* Общее состояние нашего приложения.
*/
struct Engine {
	struct android_app* app;

	ASensorManager* sensorManager;
	const ASensor* accelerometerSensor;
	ASensorEventQueue* sensorEventQueue;

	int animating;
	EGLDisplay display;
	EGLSurface surface;
	EGLContext context;
	int32_t width;
	int32_t height;
	struct SavedState state;
};

class GameApplication
{
	struct android_app* state;
public:
	Engine engine;


	GameApplication(struct android_app* state);
	virtual ~GameApplication();

	int init();
	void run();
	void step();
};

