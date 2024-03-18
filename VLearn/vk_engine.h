#pragma once

#include "vk_types.h"

struct FrameData {
	VkCommandPool _commandPool;
	VkCommandBuffer _mainCommandBuffer;
};

constexpr uint32_t FRAME_OVERLAP = 2;

class VulkanEngine {
public:
	bool _isInitialized{ false };
	int _frameNumber{ 0 };
	bool stop_rendering{ false };
	VkExtent2D _windowExtent{ 1700, 900 };

	struct SDL_Window* _window{ nullptr };
	static VulkanEngine& Get();

	VkInstance _instance; // instance
	VkDebugUtilsMessengerEXT _debug_messenger; // validation layer
	VkPhysicalDevice _GPU; // chosen GPU
	VkDevice _device; // vulkan driver device abstraction
	VkSurfaceKHR _surface; // surface for drawing

	// swapchain things
	VkSwapchainKHR _swapchain;
	VkFormat _swapchainImageFormat;
	std::vector<VkImage> _swapchainImages;
	std::vector<VkImageView> _swapchainImageViews;
	VkExtent2D _swapchainExtent;

	// Frames
	FrameData _frames[FRAME_OVERLAP];
	FrameData& get_current_frame() { return _frames[_frameNumber % FRAME_OVERLAP]; }

	// Queues
	VkQueue _graphicsQueue;
	uint32_t _graphicsQueueFamily;

	// initialize everything in the engine
	void init();

	// shuts down the engine
	void cleanup();

	// draw loop
	void draw();

	// run main loop
	void run();

private:
	void init_vulkan();
	void create_swapchain(uint32_t width, uint32_t height);
	void destroy_swapchain();
	void init_commands();
	void init_sync_structures();
};