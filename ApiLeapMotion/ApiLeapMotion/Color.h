#pragma once

union Color {
	unsigned int      c; 
	struct argbTag
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
	} argb;
};
