#pragma once

#include "vk_types.h"

namespace vkinit {
	// command pools and buffers
	VkCommandPoolCreateInfo command_pool_create_info(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags);
	VkCommandBufferAllocateInfo command_buffer_allocate_info(VkCommandPool pool, uint32_t count);
	VkCommandBufferBeginInfo command_buffer_begin_info(VkCommandBufferUsageFlags flags);
	VkCommandBufferSubmitInfo command_buffer_submit_info(VkCommandBuffer cmd);

	// semaphores and fences
	VkFenceCreateInfo fence_create_info(VkFenceCreateFlags flags);
	VkSemaphoreCreateInfo semaphore_create_info(VkSemaphoreCreateFlags flags);
	VkSemaphoreSubmitInfo semaphore_submit_info(VkPipelineStageFlags2 stageMask, VkSemaphore semaphore);

	// image transformations
	VkImageSubresourceRange image_subresource_range(VkImageAspectFlags aspectMask);

	// others
	VkSubmitInfo2 submit_info(VkCommandBufferSubmitInfo* cmd, VkSemaphoreSubmitInfo* signalSemaphoreInfo, VkSemaphoreSubmitInfo* waitSemaphoreInfo);
}