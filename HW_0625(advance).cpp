#include <iostream>

using namespace std;


//1. 세개의 숫자를 입력받아서 가장 큰 수를 출력하는 프로그램을 구현하라
//조건 연산자를 사용하라.
int main1() {
	
	int num0, num1, num2;
	int max = 0;
	
	cout << "세 개의 숫자를 입력하세요 : " << endl;
	cin >> num0 >> num1 >> num2;
	max=((num0 > num1) ? num0 : num1);
	max = ((num2 > num0) ? num2 : num0);
	cout << "가장 큰 수는 " << max << " 입니다. " << endl;
	return 0;
}

//
//2. unsigned char val1 = 0x05, val2 = 0x07, val3 = 0 입니다.
//비트이동연산자와 비트논리연산자를 이용해서 두개의 값을 하나로 합치고 출력하세요.
//즉, val3에는 0x57이 담겨있어야 합니다.

int main2() {

	unsigned char val1 = 0X05, val2 = 0X07, val3 = 0;

	cout<<"val3은 0x" << std::hex << ((val1<<4)|val2)<<" 입니다."<<endl;
	unsigned char num = ((val1 << 4) | val2);
	printf("%#x %d\n", num, num);


	return 0;
}


//3. unsigned char val1 = 0x57, val2 = 0, val3 = 0 입니다.
//비트이동연산자와 비트논리연산자를 이용해서 하나의 값을 두개로 분리하고 출력하세요.
//val2는 0x5, val3는 0x7이 담겨있어야 합니다.

int main3() {

	unsigned char val1 = 0X57, val2 = 0, val3 = 0;
	cout << "val2는 0X"<< (val1>>4)<<" 입니다. " << endl;
	cout << "val3는 0X"<< (val1&0X0F)<<" 입니다. " << endl;

	return 0;
}



//4. 미국 인디언들은 1627년에 뉴욕 맨하튼 섬을
//네덜란드 이주자들에게 단돈 24달러에 팔았다고 합니다.
//지금 생각하면 헐값에 판 것 같지만,
//이 돈을 지금까지 은행에 넣어두고
//8 % 의 이자를 복리로 받았다면 지금쯤 엄청난 금액이
//되어 있을 거라고 합니다.
//2010년을 기준으로 이 돈의 가치가 얼마나 되는지
//계산하는 프로그램을 작성하세요.
//복리란 1년이 지날때마다 8 % 가 원금에 포함이 되어서
//그 금액이 다시 원금이 되는 것을 말합니다.
//
//
//
//5. 5를 입력하면
//o
//*o
//**o
//***o
//****o
//이렇게 출력하세요.
int main() {



}


//6. 홀수를 입력하면 됩니다.
//7를 입력하면
//   *
//  ***
// *****
//*******
// *****
//  ***
//   *
//이렇게 출력하세요.
