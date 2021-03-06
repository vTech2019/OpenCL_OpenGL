// GPGPU test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "clDevice.h"
//#ifdef _DEBUG
//#pragma comment(lib, "opencv_world400d.lib")
//#else
//#pragma comment(lib, "opencv_world400.lib")
//#endif

int main()
{
	clPlatform platform;
	cl_char* place = (cl_char*)_aligned_malloc(platform.getNumberDevices() * sizeof(clDevice), alignof(clDevice));
	clDevice** devices = (clDevice**)malloc(platform.getNumberDevices() * sizeof(clDevice*));
	cl_char* aligned_place = place;
	for (size_t i = 0; i < platform.getNumberDevices(); i++) {
		devices[i] = new(aligned_place) clDevice(&platform, i);
		aligned_place += sizeof(clDevice);
	}

	for (size_t i = 0; i < platform.getNumberDevices(); i++) {
		devices[i]->~clDevice();
	}
	free(devices);
	_aligned_free(place);
	std::cout << "Hello World!\n";
}