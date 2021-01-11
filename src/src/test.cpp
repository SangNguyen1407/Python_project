file.h
extern int num;

file1.cpp
int num = 0;
int main ()
{
	cout << num << endl;
	test_function();
	cout << num << endl;
	return 0;
}

file2.cpp
int test_function()
{
	num += 10;
	return 0;
}