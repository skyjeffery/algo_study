//嵌套结构示例
#include <stdio.h>
#define	LEN 20
const char* msgs[5] =
{
	"    Thank you for the wonder evening ,",
	"you certainly prove that a ",
	"is a special kind of guy.We must get together",
	"over a delicious",
	" and have a few laughs"

};

struct names {//结构1
	char first[LEN];
	char last[LEN];
};

struct guys {//结构2
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	struct guys fellow = {
		{"James","Jeffery"},
		"beek noodle",
		"automatic engineer",
		25000.00
	};
	
	printf("Dear %s,\n\n", fellow.handle.first);
	printf("%s%s.\n", msgs[0], fellow.handle.last);
	printf("%s%s\n", msgs[1],fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s.\n", msgs[3],fellow.favfood,msgs[4]);
	printf("\n%40s%s\n", " ", "See you soon");
	printf("%40s%s\n", " ", "your girlfriend");

	return 0;



}