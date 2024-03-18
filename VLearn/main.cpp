#include "vk_engine.h"

int main(int argc, char** argv) {
	VulkanEngine engine;
	// initialize the engine
	engine.init();
	// run it
	engine.run();
	// after closing window terminate everything and quit
	engine.cleanup();
	return 0;
}