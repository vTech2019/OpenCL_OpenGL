#include "clDevice.h"


void CL_CALLBACK pfnBuildProgram(cl_program program, void *userData)
{
	cl_device_id *deviceID = (cl_device_id*)userData;
	cl_build_status status;
	size_t length = 0;
	cl_int ret = clGetProgramBuildInfo(program, *deviceID, CL_PROGRAM_BUILD_STATUS, sizeof(cl_build_status), &status, &length);
	if (status == CL_BUILD_IN_PROGRESS)
	{
		cl_int ret = clGetProgramBuildInfo(program, *deviceID, CL_PROGRAM_BUILD_LOG, NULL, NULL, &length);
		if (ret != CL_SUCCESS)
			printf("clGetProgramBuildInfo - %d", ret);
		cl_char* data = (cl_char*)malloc(length + 1);
		data[length] = 0;
		ret = clGetProgramBuildInfo(program, *deviceID, CL_PROGRAM_BUILD_LOG, length, data, NULL);
		if (ret != CL_SUCCESS)
			printf("clGetProgramBuildInfo - %d", ret);
		printf("CL_BUILD_IN_PROGRESS - %s\n", data);
		free(data);
	}
	else if (status == CL_BUILD_ERROR)
	{
		cl_int ret = clGetProgramBuildInfo(program, *deviceID, CL_PROGRAM_BUILD_LOG, NULL, NULL, &length);
		if (ret != CL_SUCCESS)
			printf("clGetProgramBuildInfo - %d", ret);
		cl_char* data = (cl_char*)malloc(length + 1);
		data[length] = 0;
		ret = clGetProgramBuildInfo(program, *deviceID, CL_PROGRAM_BUILD_LOG, length, data, NULL);
		if (ret != CL_SUCCESS)
			printf("clGetProgramBuildInfo - %d", ret);
		printf("CL_BUILD_ERROR - %s", data);
		free(data);
	}
	else if (status == CL_BUILD_NONE) {
		printf("CL_BUILD_NONE");
	}
	else if (status == CL_BUILD_SUCCESS) {
		printf("CL_BUILD_SUCCESS");
	}
}

const char* getInformationError(cl_int codeError)
{
	switch (codeError)
	{
	case CL_SUCCESS:
		return "CL_SUCCESS";
	case CL_DEVICE_NOT_FOUND:
		return "CL_DEVICE_NOT_FOUND";
	case CL_DEVICE_NOT_AVAILABLE:
		return "CL_DEVICE_NOT_AVAILABLE";
	case CL_COMPILER_NOT_AVAILABLE:
		return "CL_COMPILER_NOT_AVAILABLE";
	case CL_MEM_OBJECT_ALLOCATION_FAILURE:
		return "CL_MEM_OBJECT_ALLOCATION_FAILURE";
	case CL_OUT_OF_RESOURCES:
		return "CL_OUT_OF_RESOURCES";
	case CL_OUT_OF_HOST_MEMORY:
		return "CL_OUT_OF_HOST_MEMORY";
	case CL_PROFILING_INFO_NOT_AVAILABLE:
		return "CL_PROFILING_INFO_NOT_AVAILABLE";
	case CL_MEM_COPY_OVERLAP:
		return "CL_MEM_COPY_OVERLAP";
	case CL_IMAGE_FORMAT_MISMATCH:
		return "CL_IMAGE_FORMAT_MISMATCH";
	case CL_IMAGE_FORMAT_NOT_SUPPORTED:
		return "CL_IMAGE_FORMAT_NOT_SUPPORTED";
	case CL_BUILD_PROGRAM_FAILURE:
		return "CL_BUILD_PROGRAM_FAILURE";
	case CL_MAP_FAILURE:
		return "CL_MAP_FAILURE";
	case CL_MISALIGNED_SUB_BUFFER_OFFSET:
		return "CL_MISALIGNED_SUB_BUFFER_OFFSET";
	case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST:
		return "CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST";
	case CL_COMPILE_PROGRAM_FAILURE:
		return "CL_COMPILE_PROGRAM_FAILURE";
	case CL_LINKER_NOT_AVAILABLE:
		return "CL_LINKER_NOT_AVAILABLE";
	case CL_LINK_PROGRAM_FAILURE:
		return "CL_LINK_PROGRAM_FAILURE";
	case CL_DEVICE_PARTITION_FAILED:
		return "CL_DEVICE_PARTITION_FAILED";
	case CL_KERNEL_ARG_INFO_NOT_AVAILABLE:
		return "CL_KERNEL_ARG_INFO_NOT_AVAILABLE";
	case CL_INVALID_VALUE:
		return "CL_INVALID_VALUE";
	case CL_INVALID_DEVICE_TYPE:
		return "CL_INVALID_DEVICE_TYPE";
	case CL_INVALID_PLATFORM:
		return "CL_INVALID_PLATFORM";
	case CL_INVALID_DEVICE:
		return "CL_INVALID_DEVICE";
	case CL_INVALID_CONTEXT:
		return "CL_INVALID_CONTEXT";
	case CL_INVALID_QUEUE_PROPERTIES:
		return "CL_INVALID_QUEUE_PROPERTIES";
	case CL_INVALID_COMMAND_QUEUE:
		return "CL_INVALID_COMMAND_QUEUE";
	case CL_INVALID_HOST_PTR:
		return "CL_INVALID_HOST_PTR";
	case CL_INVALID_MEM_OBJECT:
		return "CL_INVALID_MEM_OBJECT";
	case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:
		return "CL_INVALID_IMAGE_FORMAT_DESCRIPTOR";
	case CL_INVALID_IMAGE_SIZE:
		return "CL_INVALID_IMAGE_SIZE";
	case CL_INVALID_SAMPLER:
		return "CL_INVALID_SAMPLER";
	case CL_INVALID_BINARY:
		return "CL_INVALID_BINARY";
	case CL_INVALID_BUILD_OPTIONS:
		return "CL_INVALID_BUILD_OPTIONS";
	case CL_INVALID_PROGRAM:
		return "CL_INVALID_PROGRAM";
	case CL_INVALID_PROGRAM_EXECUTABLE:
		return "CL_INVALID_PROGRAM_EXECUTABLE";
	case CL_INVALID_KERNEL_NAME:
		return "CL_INVALID_KERNEL_NAME";
	case CL_INVALID_KERNEL_DEFINITION:
		return "CL_INVALID_KERNEL_DEFINITION";
	case CL_INVALID_KERNEL:
		return "CL_INVALID_KERNEL";
	case CL_INVALID_ARG_INDEX:
		return "CL_INVALID_ARG_INDEX";
	case CL_INVALID_ARG_VALUE:
		return "CL_INVALID_ARG_VALUE";
	case CL_INVALID_ARG_SIZE:
		return "CL_INVALID_ARG_SIZE";
	case CL_INVALID_KERNEL_ARGS:
		return "CL_INVALID_KERNEL_ARGS";
	case CL_INVALID_WORK_DIMENSION:
		return "CL_INVALID_WORK_DIMENSION";
	case CL_INVALID_WORK_GROUP_SIZE:
		return "CL_INVALID_WORK_GROUP_SIZE";
	case CL_INVALID_WORK_ITEM_SIZE:
		return "CL_INVALID_WORK_ITEM_SIZE";
	case CL_INVALID_GLOBAL_OFFSET:
		return "CL_INVALID_GLOBAL_OFFSET";
	case CL_INVALID_EVENT_WAIT_LIST:
		return "CL_INVALID_EVENT_WAIT_LIST";
	case CL_INVALID_EVENT:
		return "CL_INVALID_EVENT";
	case CL_INVALID_OPERATION:
		return "CL_INVALID_OPERATION";
	case CL_INVALID_GL_OBJECT:
		return "CL_INVALID_GL_OBJECT";
	case CL_INVALID_BUFFER_SIZE:
		return "CL_INVALID_BUFFER_SIZE";
	case CL_INVALID_MIP_LEVEL:
		return "CL_INVALID_MIP_LEVEL";
	case CL_INVALID_GLOBAL_WORK_SIZE:
		return "CL_INVALID_GLOBAL_WORK_SIZE";
	case CL_INVALID_PROPERTY:
		return "CL_INVALID_PROPERTY";
	case CL_INVALID_IMAGE_DESCRIPTOR:
		return "CL_INVALID_IMAGE_DESCRIPTOR";
	case CL_INVALID_COMPILER_OPTIONS:
		return "CL_INVALID_COMPILER_OPTIONS";
	case CL_INVALID_LINKER_OPTIONS:
		return "CL_INVALID_LINKER_OPTIONS";
	case CL_INVALID_DEVICE_PARTITION_COUNT:
		return "CL_INVALID_DEVICE_PARTITION_COUNT";
	default:
		return "CL_INVALID_INDEX";
	}
}

void platformInfo(cl_platform_id platform, cl_platform_info information, const cl_char textInformation[], cl_char* strPlatformInfo[5]) {
	size_t length;
	size_t typeInfo = information - 0x900;
	CL_CHECK(clGetPlatformInfo(platform, information, NULL, NULL, &length), textInformation);
	strPlatformInfo[typeInfo] = (cl_char*)malloc(length + 1);
	strPlatformInfo[typeInfo][length] = 0;
	CL_CHECK(clGetPlatformInfo(platform, information, length, strPlatformInfo[typeInfo], NULL), textInformation);
	printf("%s - %s\n", textInformation, strPlatformInfo[typeInfo]);
}

void deviceInfo(cl_device_id device, cl_platform_info information, const cl_char textInformation[], void** data, cl_uint lengthData) {
	size_t length;
	CL_CHECK(clGetDeviceInfo(device, information, NULL, NULL, &length), textInformation);
	if (lengthData != length) {
		*data = (cl_char*)malloc((length) * sizeof(cl_char));
		CL_CHECK(clGetDeviceInfo(device, information, length, *data, NULL), textInformation);
	}
	else {
		CL_CHECK(clGetDeviceInfo(device, information, length, &(*((cl_char*)data)), NULL), textInformation);
	}
}

clPlatform::clPlatform() {
	cl_int errorCode;
	if (!platforms) {
		CL_CHECK(clGetPlatformIDs(NULL, NULL, &numberPlatforms), "clGetPlatformIDs");
		platforms = (cl_platform_id*)malloc(numberPlatforms * sizeof(cl_platform_id));
		context = (cl_context*)malloc(numberPlatforms * sizeof(cl_context));
		platformDevices = (cl_uint*)malloc(numberPlatforms * sizeof(cl_uint));
		CL_CHECK(clGetPlatformIDs(numberPlatforms, platforms, NULL), "clGetPlatformIDs");
	}
	if (numberPlatforms == 0) return;

	CL_CHECK(clGetDeviceIDs(platforms[getNextPlatform], CL_DEVICE_TYPE_ALL, NULL, NULL, &platformDevices[getNextPlatform]), "clGetDeviceIDs");
	devices = (cl_device_id*)realloc(devices, (platformDevices[getNextPlatform] + numberDevices) * sizeof(cl_device_id));
	queue = (cl_command_queue*)realloc(queue, (platformDevices[getNextPlatform] + numberDevices) * sizeof(cl_command_queue));
	CL_CHECK(clGetDeviceIDs(platforms[getNextPlatform], CL_DEVICE_TYPE_ALL, platformDevices[getNextPlatform], devices + numberDevices, NULL), "clGetDeviceIDs");
	cl_context_properties properties[3] = { CL_CONTEXT_PLATFORM, (cl_context_properties)platforms[getNextPlatform], 0 };
	context[getNextPlatform] = clCreateContext(properties, platformDevices[getNextPlatform], devices + numberDevices, NULL, NULL, &errorCode);
	CL_CHECK(errorCode, "clCreateContext");
	for (cl_uint j = 0; j < platformDevices[getNextPlatform]; j++) {
		queue[numberDevices + j] = clCreateCommandQueue(context[getNextPlatform], devices[numberDevices + j], CL_QUEUE_PROFILING_ENABLE, &errorCode);
		CL_CHECK(errorCode, "clCreateCommandQueue");
	}
	numberDevices += platformDevices[getNextPlatform];
	getNextPlatform++;
}

cl_command_queue* clPlatform::getCommandQueueID(cl_uint index) {
	return index < numberDevices ? &queue[index] : NULL;
}
cl_device_id* clPlatform::getDeviceID(cl_uint index) {
	return index < numberDevices ? &devices[index] : NULL;
}
cl_platform_id* clPlatform::getPlatformID(cl_uint index) {
	if (index > numberDevices)
		return NULL;
	cl_uint sum = 0;
	for (size_t i = 0; i < numberPlatforms; i++) {
		sum += platformDevices[i];
		if (index < sum)
			return &platforms[i];
	}
	return NULL;
}
cl_context* clPlatform::getContextID(cl_uint index) {
	if (index > numberDevices)
		return NULL;
	cl_uint sum = 0;
	for (cl_uint i = 0; i < numberPlatforms; i++) {
		sum += platformDevices[i];
		if (index < sum)
			return &context[i];
	}
	return NULL;
}

clPlatform::~clPlatform() {
	for (cl_uint i = 0; i < numberDevices; i++) {
		clReleaseCommandQueue(queue[i]);
		clReleaseDevice(devices[i]);
	}
	for (cl_uint i = 0; i < numberPlatforms; i++)
		clReleaseContext(context[i]);
	if (context) free(context);
	if (queue) free(queue);
	if (devices) free(devices);
	if (platforms) free(platforms);
	if (platformDevices) free(platformDevices);
}
clDevice::clDevice(clPlatform* platformData, cl_uint indexDevice)
{
	memset(this, 0, sizeof(*this));
	if (platformData->getNumberDevices() < indexDevice) return;
	platform = platformData->getPlatformID(indexDevice);
	context = platformData->getContextID(indexDevice);
	device = platformData->getDeviceID(indexDevice);
	queue = platformData->getCommandQueueID(indexDevice);

	platformInfo(*platform, CL_PLATFORM_VENDOR, (const cl_char*)"CL_PLATFORM_VENDOR", profileVersionNameVendorExtensions);
	platformInfo(*platform, CL_PLATFORM_NAME, (const cl_char*)"CL_PLATFORM_NAME", profileVersionNameVendorExtensions);
	platformInfo(*platform, CL_PLATFORM_VERSION, (const cl_char*)"CL_PLATFORM_VERSION", profileVersionNameVendorExtensions);
	platformInfo(*platform, CL_PLATFORM_PROFILE, (const cl_char*)"CL_PLATFORM_PROFILE", profileVersionNameVendorExtensions);
	platformInfo(*platform, CL_PLATFORM_EXTENSIONS, (const cl_char*)"CL_PLATFORM_EXTENSIONS", profileVersionNameVendorExtensions);

	deviceInfo(*device, CL_DEVICE_EXTENSIONS, (const cl_char*)"CL_DEVICE_EXTENSIONS", (void**)&DeviceInfo.deviceExtensions, 0);
	deviceInfo(*device, CL_DEVICE_VENDOR, (const cl_char*)"CL_DEVICE_VENDOR_ID", (void**)&DeviceInfo.deviceVendor, 0);
	deviceInfo(*device, CL_DEVICE_TYPE, (const cl_char*)"CL_DEVICE_TYPE", (void**)&DeviceInfo.deviceType, sizeof(cl_device_type));
	deviceInfo(*device, CL_DEVICE_LOCAL_MEM_TYPE, (const cl_char*)"CL_DEVICE_LOCAL_MEM_TYPE", (void**)&DeviceInfo.localMemoryType, sizeof(cl_device_local_mem_type));
	deviceInfo(*device, CL_DEVICE_MAX_COMPUTE_UNITS, (const cl_char*)"CL_DEVICE_MAX_COMPUTE_UNITS", (void**)&DeviceInfo.maxComputeUnits, sizeof(cl_uint));
	deviceInfo(*device, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, (const cl_char*)"CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS", (void**)&DeviceInfo.workItemDemension, sizeof(cl_uint));
	deviceInfo(*device, CL_DEVICE_MAX_WORK_ITEM_SIZES, (const cl_char*)"CL_DEVICE_MAX_WORK_ITEM_SIZES", (void**)&DeviceInfo.workItemSizes, 3 * sizeof(size_t));
	deviceInfo(*device, CL_DEVICE_LOCAL_MEM_SIZE, (const cl_char*)"CL_DEVICE_LOCAL_MEM_SIZE", (void**)&DeviceInfo.localMemorySize, sizeof(cl_ulong));
	deviceInfo(*device, CL_DEVICE_MAX_MEM_ALLOC_SIZE, (const cl_char*)"CL_DEVICE_MAX_MEM_ALLOC_SIZE", (void**)&DeviceInfo.maxGlobalMemoryAllocate, sizeof(cl_ulong));
	deviceInfo(*device, CL_DEVICE_MAX_PARAMETER_SIZE, (const cl_char*)"CL_DEVICE_MAX_PARAMETER_SIZE", (void**)&DeviceInfo.maximumParametersInKernel, sizeof(size_t));
	deviceInfo(*device, CL_DEVICE_MAX_WORK_GROUP_SIZE, (const cl_char*)"CL_DEVICE_MAX_WORK_GROUP_SIZE", (void**)&DeviceInfo.maxWorkGroupSize, sizeof(size_t));
	deviceInfo(*device, CL_DEVICE_GLOBAL_MEM_SIZE, (const cl_char*)"CL_DEVICE_GLOBAL_MEM_SIZE", (void**)&DeviceInfo.globalMemSize, sizeof(cl_ulong));
	deviceInfo(*device, CL_DEVICE_IMAGE_SUPPORT, (const cl_char*)"CL_DEVICE_IMAGE_SUPPORT", (void**)&DeviceInfo.supportImages, sizeof(cl_bool));
	deviceInfo(*device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR, (const cl_char*)"CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR", (void**)&DeviceInfo.preferVectorChar, sizeof(cl_uint));
	deviceInfo(*device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT, (const cl_char*)"CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT", (void**)&DeviceInfo.preferVectorShort, sizeof(cl_uint));
	deviceInfo(*device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT, (const cl_char*)"CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT", (void**)&DeviceInfo.preferVectorInt, sizeof(cl_uint));
	deviceInfo(*device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG, (const cl_char*)"CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG", (void**)&DeviceInfo.preferVectorLong, sizeof(cl_uint));
	deviceInfo(*device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT, (const cl_char*)"CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT", (void**)&DeviceInfo.preferVectorFloat, sizeof(cl_uint));
	deviceInfo(*device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE, (const cl_char*)"CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE", (void**)&DeviceInfo.preferVectorDouble, sizeof(cl_uint));		
	if (DeviceInfo.supportImages) {
		deviceInfo(*device, CL_DEVICE_IMAGE2D_MAX_HEIGHT, (const cl_char*)"CL_DEVICE_IMAGE2D_MAX_HEIGHT", (void**)&DeviceInfo.maxHeightImage2D, sizeof(size_t));
		deviceInfo(*device, CL_DEVICE_IMAGE2D_MAX_WIDTH, (const cl_char*)"CL_DEVICE_IMAGE2D_MAX_WIDTH", (void**)&DeviceInfo.maxWidthImage2D, sizeof(size_t));
		deviceInfo(*device, CL_DEVICE_IMAGE3D_MAX_HEIGHT, (const cl_char*)"CL_DEVICE_IMAGE3D_MAX_HEIGHT", (void**)&DeviceInfo.maxHeightImage3D, sizeof(size_t));
		deviceInfo(*device, CL_DEVICE_IMAGE3D_MAX_WIDTH, (const cl_char*)"CL_DEVICE_IMAGE3D_MAX_WIDTH", (void**)&DeviceInfo.maxWidthImage3D, sizeof(size_t));
		deviceInfo(*device, CL_DEVICE_IMAGE3D_MAX_DEPTH, (const cl_char*)"CL_DEVICE_IMAGE3D_MAX_DEPTH", (void**)&DeviceInfo.maxDepthImage3D, sizeof(size_t));
	}
}

bool clDevice::clPushProgram(cl_char * text, size_t lengthText, const cl_char* options)
{
	cl_int errorCode;
	namesPrograms = (cl_char**)realloc(namesPrograms, (numberPrograms + 1) * sizeof(cl_char*));
	namesPrograms[numberPrograms] = (cl_char*)malloc(lengthText * sizeof(cl_char));
	memcpy(namesPrograms[numberPrograms], text, lengthText);
	programDevice = (cl_program*)realloc(programDevice, (numberPrograms + 1) * sizeof(cl_program));
	programDevice[numberPrograms] = clCreateProgramWithSource(*context, 1, (const char**)&text, NULL, &errorCode);
	CL_CHECK(errorCode, "clCreateProgramWithSource");
	CL_CHECK(clBuildProgram(*programDevice, 1, device, (const char*)options, pfnBuildProgram, (void*)device), "clBuildProgram");
	numberPrograms++;
	return true;
}
bool clDevice::clPushKernel(cl_char * text, size_t lengthText)
{
	cl_int errorCode;
	cl_kernel kernel = NULL;
	for (size_t i = 0; i < numberPrograms; i++) {
		kernel = clCreateKernel(programDevice[i], (const char*)text, &errorCode);
		if (CL_INVALID_KERNEL_NAME != errorCode)
			CL_CHECK(errorCode, "clCreateKernel");
	}
	if (kernel == NULL)
		return false;
	namesKernels = (cl_char**)realloc(namesKernels, (numberKernels + 1) * sizeof(cl_char*));
	namesKernels[numberKernels] = (cl_char*)malloc(lengthText * sizeof(cl_char));
	memcpy(namesKernels[numberKernels], text, lengthText);
	kernels = (cl_kernel*)realloc(kernels, (numberKernels + 1) * sizeof(cl_kernel));
	kernels[numberKernels] = kernel;
	numberKernels++;
	return true;
}

cl_bool clDevice::mallocBufferMemory(const void** data, size_t* lengthData, size_t numberArrays, size_t lengthType) {
	ptrMemoryDevice = (cl_mem*)realloc(ptrMemoryDevice, (numberObjectMemory + numberArrays) * sizeof(cl_mem));
	cl_int errors;
	for (size_t i = 0; i < numberArrays; i++) {
		ptrMemoryDevice[numberObjectMemory + i] = clCreateBuffer(*context, CL_MEM_READ_WRITE, lengthType * lengthData[i], NULL, &errors);
		CL_CHECK(errors, "clCreateBuffer");
		if (errors) {
			ptrMemoryDevice = (cl_mem*)realloc(ptrMemoryDevice, (numberObjectMemory) * sizeof(cl_mem));
			return false;
		}
	}
	for (size_t i = 0; i < numberArrays; i++) {
		CL_CHECK(clEnqueueWriteBuffer(*queue, ptrMemoryDevice[numberObjectMemory + i], CL_FALSE, 0, lengthType * lengthData[i], data[i], NULL, NULL, NULL), "clEnqueueWriteBuffer");
	}
	numberObjectMemory += numberArrays;
	return true;
}

cl_bool clDevice::setArguments(cl_uint indexKernel, cl_uint* indicesMemoryBuffer, cl_uint numberIndicesMemoryBuffer,
	void* arguments, cl_char* typeArgubents, cl_uint numberArguments) {
	for (size_t i = 0; i < numberIndicesMemoryBuffer; i++) {
		if (indicesMemoryBuffer[i] < numberObjectMemory)
			CL_CHECK(clSetKernelArg(kernels[indexKernel], 0, sizeof(ptrMemoryDevice[indicesMemoryBuffer[i]]), &ptrMemoryDevice[indicesMemoryBuffer[i]]), "clSetKernelArg");
		else {
			printf("Error index in clSetKernelArg");
			return false;
		}
	}
	size_t offset = 0;
	cl_char* _arguments = (cl_char*)arguments;
	for (size_t i = 0; i < numberArguments; i++) {
		CL_CHECK(clSetKernelArg(kernels[indexKernel], 0, sizeof(typeArgubents[i]), &_arguments[offset]), "clSetKernelArg");
		offset += typeArgubents[i];
	}
	return true;
}


cl_bool clDevice::startCalculate(cl_uint indexKernel, size_t globalWork[3]) {

	cl_event kernelEvent;

	CL_CHECK(clEnqueueNDRangeKernel(*queue, kernels[indexKernel], 2, NULL, globalWork, NULL, NULL, NULL, &kernelEvent), "clEnqueueNDRangeKernel");

	cl_ulong time_start, time_end;
	CL_CHECK(clWaitForEvents(1, &kernelEvent), "clWaitForEvents");
	CL_CHECK(clGetEventProfilingInfo(kernelEvent, CL_PROFILING_COMMAND_START, sizeof(time_start), &time_start, NULL), "clGetEventProfilingInfo");
	CL_CHECK(clGetEventProfilingInfo(kernelEvent, CL_PROFILING_COMMAND_END, sizeof(time_end), &time_end, NULL), "clGetEventProfilingInfo");
	const cl_ulong total_time = time_end - time_start;
	const cl_double time = total_time / 1000000.0;
	printf("Execution time:\t\t%0f ms\n", time);
	return true;
}
cl_bool clDevice::readData(void** returnedData, cl_uint* indicesReadData, cl_char* typeArgubentsReturnedData, cl_ulong* lengthWrite, cl_uint numberIndicesReadData) {
	cl_char** hostData = (cl_char**)returnedData;
	size_t offset = 0;
	for (size_t i = 0; i < numberIndicesReadData; i++) {
		CL_CHECK(clEnqueueReadBuffer(*queue, ptrMemoryDevice[indicesReadData[i]], CL_FALSE, 0, typeArgubentsReturnedData[i] * lengthWrite[i], hostData[offset], NULL, NULL, NULL), "clEnqueueReadBuffer");
		offset += typeArgubentsReturnedData[i];
	}
	return true;
}
cl_char* clDevice::getNameKernel(cl_uint index) {
	return numberKernels > index ? namesKernels[numberKernels] : NULL;
}
cl_char* clDevice::getNameProgram(cl_uint index) {
	return numberPrograms > index ? namesPrograms[numberPrograms] : NULL;
}
clDevice::~clDevice()
{
	free(profileVersionNameVendorExtensions[0]);
	free(profileVersionNameVendorExtensions[1]);
	free(profileVersionNameVendorExtensions[2]);
	free(profileVersionNameVendorExtensions[3]);
	free(profileVersionNameVendorExtensions[4]);

	for (size_t i = 0; i < numberKernels; i++)
		clReleaseKernel(kernels[i]),
		free(namesKernels[i]);
	for (size_t i = 0; i < numberPrograms; i++)
		clReleaseProgram(programDevice[i]),
		free(namesPrograms[i]);

	if (kernels) free(kernels);
	if (programDevice) free(programDevice);
	if (namesPrograms) free(namesPrograms);
	if (namesKernels) free(namesKernels);
}