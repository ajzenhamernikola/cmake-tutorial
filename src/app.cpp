#include <iostream>
#include <string>
#include <filesystem>
#include <random>

#include <stb_image.h>
#include <stb_image_write.h>

namespace fs = std::filesystem;

int main()
{
	using namespace std;

	int width, height, num_of_channels;
	string input, output;

	cout << "Enter the input image file path: ";
	cin >> input;

	if (!fs::exists(input))
	{
		cerr << "The file you entered does not exists" << endl;
		exit(EXIT_FAILURE);
	}

	auto *data = stbi_load(input.c_str(), &width, &height, &num_of_channels, 1);

	if (!data)
	{
		cout << "There is a problem with loading an image " << input << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Image " << input << " with dimensions " << width << "x" << height << " is successfully loaded" << endl;

	output = input + "_modified.jpg";
	const auto result_code = stbi_write_jpg(output.c_str(), width, height, 1, data, 100);

	if (!result_code)
	{
		cout << "There is a problem with saving the image " << output << endl;
		exit(EXIT_FAILURE);
	}

	cout << "The image " << output << " is successfully saved" << endl;

	return 0;
}
