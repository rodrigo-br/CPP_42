#include "whatever.hpp"

void print_line() {
	std::cout << std::string(42, '-') << std::endl;
}

void t(std::string msg) {
	std::cout << "\t\t" << msg << std::endl;
}

template <typename T>
void test_template(T a, T b) {
	print_line(); t("Max");
	std::cout << ::max(a, b) << std::endl;

	print_line(); t("Min");
	std::cout << ::min(a, b) << std::endl;

	print_line(); t("before Swap");
	std::cout << "a = " << a << "\nb = " << b << std::endl;
	swap(a, b);
	print_line(); t("After Swap");
	std::cout << "a = " << a << "\nb = " << b << std::endl;

	print_line(); t("min < max");
	std::cout << (::min(a, b) < ::max(a, b)) << std::endl;

	print_line(); t("min > max");
	std::cout << (::min(a, b) > ::max(a, b)) << std::endl;

	print_line(); t("min == max");
	std::cout << (::min(a, b) == ::max(a, b)) << std::endl;

	print_line(); t("min != max");
	std::cout << (::min(a, b) != ::max(a, b)) << std::endl;
}

int main(void)
{
	std::cout << std::boolalpha;
	print_line(); t("Test with INT");
	int a = 69;
	int b = 2;
	test_template<int>(a, b);

	print_line(); t("Test with CHAR");
	char aa = 'a';
	char bb = 'b';
	test_template<char>(aa, bb);

	print_line(); t("Test with FLOAT");
	float aaa = 10.5f;
	float bbb = 0.1f;
	test_template<float>(aaa, bbb);

	print_line(); t("Test with STRING");
	std::string aaaa = "chaine1";
	std::string bbbb = "chaine2";
	test_template<std::string>(aaaa, bbbb);
}