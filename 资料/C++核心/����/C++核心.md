# C++���ı��

���׶���Ҫ���C++==�������==��̼�������ϸ���⣬̽��C++�еĺ��ĺ;��衣



## 1 �ڴ����ģ��

C++������ִ��ʱ�����ڴ���򻮷�Ϊ**4������**

- ����������ź�����Ķ����ƴ��룬�ɲ���ϵͳ���й����
- ȫ���������ȫ�ֱ����;�̬�����Լ�����
- ջ�����ɱ������Զ������ͷ�, ��ź����Ĳ���ֵ,�ֲ�������
- �������ɳ���Ա������ͷ�,������Ա���ͷ�,�������ʱ�ɲ���ϵͳ����







**�ڴ��������壺**

��ͬ�����ŵ����ݣ����費ͬ����������, �����Ǹ���������





### 1.1 ��������ǰ

?	�ڳ�������������exe��ִ�г���**δִ�иó���ǰ**��Ϊ��������

?	**��������**

?		��� CPU ִ�еĻ���ָ��

?		��������**����**�ģ������Ŀ���Ƕ���Ƶ����ִ�еĳ���ֻ��Ҫ���ڴ�����һ�ݴ��뼴��

?		��������**ֻ��**�ģ�ʹ��ֻ����ԭ���Ƿ�ֹ����������޸�������ָ��

?	**ȫ������**

?		ȫ�ֱ����;�̬��������ڴ�.

?		ȫ�����������˳�����, �ַ�����������������Ҳ����ڴ�.

?		==������������ڳ���������ɲ���ϵͳ�ͷ�==.













**ʾ����**

```c++
//ȫ�ֱ���
int g_a = 10;
int g_b = 10;

//ȫ�ֳ���
const int c_g_a = 10;
const int c_g_b = 10;

int main() {

	//�ֲ�����
	int a = 10;
	int b = 10;

	//��ӡ��ַ
	cout << "�ֲ�����a��ַΪ�� " << (int)&a << endl;
	cout << "�ֲ�����b��ַΪ�� " << (int)&b << endl;

	cout << "ȫ�ֱ���g_a��ַΪ�� " <<  (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b��ַΪ�� " <<  (int)&g_b << endl;

	//��̬����
	static int s_a = 10;
	static int s_b = 10;

	cout << "��̬����s_a��ַΪ�� " << (int)&s_a << endl;
	cout << "��̬����s_b��ַΪ�� " << (int)&s_b << endl;

	cout << "�ַ���������ַΪ�� " << (int)&"hello world" << endl;
	cout << "�ַ���������ַΪ�� " << (int)&"hello world1" << endl;

	cout << "ȫ�ֳ���c_g_a��ַΪ�� " << (int)&c_g_a << endl;
	cout << "ȫ�ֳ���c_g_b��ַΪ�� " << (int)&c_g_b << endl;

	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "�ֲ�����c_l_a��ַΪ�� " << (int)&c_l_a << endl;
	cout << "�ֲ�����c_l_b��ַΪ�� " << (int)&c_l_b << endl;

	system("pause");

	return 0;
}
```

��ӡ�����

![1545017602518](assets/1545017602518.png)



�ܽ᣺

* C++���ڳ�������ǰ��Ϊȫ�����ʹ�����
* �������ص��ǹ����ֻ��
* ȫ�����д��ȫ�ֱ�������̬����������
* �������д�� const���ε�ȫ�ֳ���  �� �ַ�������






### 1.2 �������к�



?	**ջ����**

?		�ɱ������Զ������ͷ�, ��ź����Ĳ���ֵ,�ֲ�������

?		ע�������Ҫ���ؾֲ������ĵ�ַ��ջ�����ٵ������ɱ������Զ��ͷ�



**ʾ����**

```c++
int * func()
{
	int a = 10;
	return &a;
}

int main() {

	int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	system("pause");

	return 0;
}
```







?	**������**

?		�ɳ���Ա�����ͷ�,������Ա���ͷ�,�������ʱ�ɲ���ϵͳ����

?		��C++����Ҫ����new�ڶ��������ڴ�

**ʾ����**

```c++
int* func()
{
	int* a = new int(10);
	return a;
}

int main() {

	int *p = func();

	cout << *p << endl;
	cout << *p << endl;
    
	system("pause");

	return 0;
}
```



**�ܽ᣺**

���������ɳ���Ա�����ٺ��ͷ�

������������new�ؼ��ֽ��п����ڴ�









### 1.3 new������



?	C++������==new==�������ڶ�����������

?	�������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷţ��ͷ����ò����� ==delete==

?	�﷨��` new ��������`

?	����new���������ݣ��᷵�ظ����ݶ�Ӧ�����͵�ָ��



**ʾ��1�� �����﷨**

```c++
int* func()
{
	int* a = new int(10);
	return a;
}

int main() {

	int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	//����delete�ͷŶ�������
	delete p;

	//cout << *p << endl; //�����ͷŵĿռ䲻�ɷ���

	system("pause");

	return 0;
}
```



**ʾ��2����������**

```c++
//������������
int main() {

	int* arr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//�ͷ����� delete ��� []
	delete[] arr;

	system("pause");

	return 0;
}

```











## 2 ����

### 2.1 ���õĻ���ʹ��

**���ã� **�����������

**�﷨��** `�������� &���� = ԭ��`



**ʾ����**

```C++
int main() {

	int a = 10;
	int &b = a;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 100;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");

	return 0;
}
```







### 2.2 ����ע������

* ���ñ����ʼ��
* �����ڳ�ʼ���󣬲����Ըı�

ʾ����

```C++
int main() {

	int a = 10;
	int b = 20;
	//int &c; //�������ñ����ʼ��
	int &c = a; //һ����ʼ���󣬾Ͳ����Ը���
	c = b; //���Ǹ�ֵ���������Ǹ�������

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}
```











### 2.3 ��������������

**���ã�**��������ʱ�������������õļ������β�����ʵ��

**�ŵ㣺**���Լ�ָ���޸�ʵ��



**ʾ����**

```C++
//1. ֵ����
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. ��ַ����
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. ���ô���
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;

	mySwap01(a, b);
	cout << "a:" << a << " b:" << b << endl;

	mySwap02(&a, &b);
	cout << "a:" << a << " b:" << b << endl;

	mySwap03(a, b);
	cout << "a:" << a << " b:" << b << endl;

	system("pause");

	return 0;
}

```



> �ܽ᣺ͨ�����ò���������Ч��ͬ����ַ������һ���ġ����õ��﷨�������













### 2.4 ��������������ֵ



���ã������ǿ�����Ϊ�����ķ���ֵ���ڵ�



ע�⣺**��Ҫ���ؾֲ���������**

�÷�������������Ϊ��ֵ



**ʾ����**

```C++
//���ؾֲ���������
int& test01() {
	int a = 10; //�ֲ�����
	return a;
}

//���ؾ�̬��������
int& test02() {
	static int a = 20;
	return a;
}

int main() {

	//���ܷ��ؾֲ�����������
	int& ref = test01();
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;

	//�����������ֵ����ô���뷵������
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}
```





?	









### 2.5 ���õı���

���ʣ�**���õı�����c++�ڲ�ʵ����һ��ָ�볣��.**

����ʾ����

```C++
//���������ã�ת��Ϊ int* const ref = &a;
void func(int& ref){
	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
}
int main(){
	int a = 10;
    
    //�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref = a; 
	ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;
    
	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
    
	func(a);
	return 0;
}
```

���ۣ�C++�Ƽ������ü�������Ϊ�﷨���㣬���ñ�����ָ�볣�����������е�ָ�����������������������













### 2.6 ��������



**���ã�**����������Ҫ���������βΣ���ֹ�����



�ں����β��б��У����Լ�==const�����β�==����ֹ�βθı�ʵ��



**ʾ����**



```C++
//����ʹ�õĳ�����ͨ�����������β�
void showValue(const int& v) {
	//v += 10;
	cout << v << endl;
}

int main() {

	//int& ref = 10;  ���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���
	//����const�Ϳ����ˣ��������Ż����룬int temp = 10; const int& ref = temp;
	const int& ref = 10;

	//ref = 100;  //����const�󲻿����޸ı���
	cout << ref << endl;

	//���������ó������÷�ֹ������޸�ʵ��
	int a = 10;
	showValue(a);

	system("pause");

	return 0;
}
```









## 3 �������

### 3.1 ����Ĭ�ϲ���



��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ�ġ�

�﷨��` ����ֵ����  ������ ������= Ĭ��ֵ��{}`



**ʾ����**

```C++
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1. ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң����붼Ҫ��Ĭ��ֵ
//2. �������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ�ϲ���
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main() {

	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func(100) << endl;

	system("pause");

	return 0;
}
```







### 3.2 ����ռλ����



C++�к������β��б��������ռλ������������ռλ�����ú���ʱ�������λ��



**�﷨��** `����ֵ���� ������ (��������){}`



���ֽ׶κ�����ռλ�����������岻�󣬵��Ǻ���Ŀγ��л��õ��ü���



**ʾ����**

```C++
//����ռλ���� ��ռλ����Ҳ������Ĭ�ϲ���
void func(int a, int) {
	cout << "this is func" << endl;
}

int main() {

	func(10,10); //ռλ���������

	system("pause");

	return 0;
}
```









### 3.3 ��������

#### 3.3.1 �������ظ���



**���ã�**������������ͬ����߸�����



**������������������**

* ͬһ����������
* ����������ͬ
* ��������**���Ͳ�ͬ**  ���� **������ͬ** ���� **˳��ͬ**



**ע��:**  �����ķ���ֵ��������Ϊ�������ص�����



**ʾ����**

```C++
//����������Ҫ��������ͬһ����������
void func()
{
	cout << "func �ĵ��ã�" << endl;
}
void func(int a)
{
	cout << "func (int a) �ĵ��ã�" << endl;
}
void func(double a)
{
	cout << "func (double a)�ĵ��ã�" << endl;
}
void func(int a ,double b)
{
	cout << "func (int a ,double b) �ĵ��ã�" << endl;
}
void func(double a ,int b)
{
	cout << "func (double a ,int b)�ĵ��ã�" << endl;
}

//��������ֵ��������Ϊ������������
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)�ĵ��ã�" << endl;
//}


int main() {

	func();
	func(10);
	func(3.14);
	func(10,3.14);
	func(3.14 , 10);
	
	system("pause");

	return 0;
}
```













#### 3.3.2 ��������ע������



* ������Ϊ��������
* ����������������Ĭ�ϲ���





**ʾ����**

```C++
//��������ע������
//1��������Ϊ��������

void func(int &a)
{
	cout << "func (int &a) ���� " << endl;
}

void func(const int &a)
{
	cout << "func (const int &a) ���� " << endl;
}


//2������������������Ĭ�ϲ���

void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) ����" << endl;
}

void func2(int a)
{
	cout << "func2(int a) ����" << endl;
}

int main() {
	
	int a = 10;
	func(a); //������const
	func(10);//������const


	//func2(10); //����Ĭ�ϲ����������壬��Ҫ����

	system("pause");

	return 0;
}
```







## **4** ��Ͷ���



C++����������������Ϊ��==��װ���̳С���̬==



C++��Ϊ==�������ﶼ��Ϊ����==���������������Ժ���Ϊ



**���磺**

?	�˿�����Ϊ�������������������䡢��ߡ�����...����Ϊ���ߡ��ܡ������Է�������...

?	��Ҳ������Ϊ������������̥�������̡�����...,��Ϊ�����ˡ������֡��ſյ�...

?	������ͬ���ʵ�==����==�����ǿ��Գ����Ϊ==��==�����������࣬�����ڳ���

### 4.1 ��װ

#### 4.1.1  ��װ������

��װ��C++���������������֮һ

��װ�����壺

* �����Ժ���Ϊ��Ϊһ�����壬���������е�����
* �����Ժ���Ϊ����Ȩ�޿���



**��װ����һ��**

?	��������ʱ�����Ժ���Ϊд��һ�𣬱�������

**�﷨��** `class ����{   ����Ȩ�ޣ� ����  / ��Ϊ  };`



**ʾ��1��**���һ��Բ�࣬��Բ���ܳ�

**ʾ�����룺**

```C++
//Բ����
const double PI = 3.14;

//1����װ������
//�����Ժ���Ϊ��Ϊһ�����壬�������������е�����

//��װһ��Բ�࣬��Բ���ܳ�
//class�������һ���࣬������ŵ�������
class Circle
{
public:  //����Ȩ��  ������Ȩ��

	//����
	int m_r;//�뾶

	//��Ϊ
	//��ȡ��Բ���ܳ�
	double calculateZC()
	{
		//2 * pi  * r
		//��ȡԲ���ܳ�
		return  2 * PI * m_r;
	}
};

int main() {

	//ͨ��Բ�࣬����Բ�Ķ���
	// c1����һ�������Բ
	Circle c1;
	c1.m_r = 10; //��Բ����İ뾶 ���и�ֵ����

	//2 * pi * 10 = = 62.8
	cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;

	system("pause");

	return 0;
}
```





**ʾ��2��**���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��





**ʾ��2���룺**

```C++
//ѧ����
class Student {
public:
	void setName(string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}

	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
	string m_name;
	int m_id;
};

int main() {

	Student stu;
	stu.setName("��������");
	stu.setID(250);
	stu.showStudent();

	system("pause");

	return 0;
}

```









**��װ�������**

�������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���

����Ȩ�������֣�



1. public        ����Ȩ��  
2. protected ����Ȩ��
3. private      ˽��Ȩ��







**ʾ����**

```C++
//����Ȩ��
//����Ȩ��  public     ���ڿ��Է���  ������Է���
//����Ȩ��  protected  ���ڿ��Է���  ���ⲻ���Է���
//˽��Ȩ��  private    ���ڿ��Է���  ���ⲻ���Է���

class Person
{
	//����  ����Ȩ��
public:
	string m_Name;

	//����  ����Ȩ��
protected:
	string m_Car;

	//���п�����  ˽��Ȩ��
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "����";
		m_Car = "������";
		m_Password = 123456;
	}
};

int main() {

	Person p;
	p.m_Name = "����";
	//p.m_Car = "����";  //����Ȩ��������ʲ���
	//p.m_Password = 123; //˽��Ȩ��������ʲ���

	system("pause");

	return 0;
}
```







#### 4.1.2 struct��class����



��C++�� struct��classΨһ��**����**������ **Ĭ�ϵķ���Ȩ�޲�ͬ**

����

* struct Ĭ��Ȩ��Ϊ����
* class   Ĭ��Ȩ��Ϊ˽��



```C++
class C1
{
	int  m_A; //Ĭ����˽��Ȩ��
};

struct C2
{
	int m_A;  //Ĭ���ǹ���Ȩ��
};

int main() {

	C1 c1;
	c1.m_A = 10; //���󣬷���Ȩ����˽��

	C2 c2;
	c2.m_A = 10; //��ȷ������Ȩ���ǹ���

	system("pause");

	return 0;
}
```













#### 4.1.3 ��Ա��������Ϊ˽��



**�ŵ�1��**�����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��

**�ŵ�2��**����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��



**ʾ����**

```C++
class Person {
public:

	//�������ÿɶ���д
	void setName(string name) {
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}


	//��ȡ���� 
	int getAge() {
		return m_Age;
	}
	//��������
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "���������!" << endl;
			return;
		}
		m_Age = age;
	}

	//��������Ϊֻд
	void setLover(string lover) {
		m_Lover = lover;
	}

private:
	string m_Name; //�ɶ���д  ����
	
	int m_Age; //ֻ��  ����

	string m_Lover; //ֻд  ����
};


int main() {

	Person p;
	//��������
	p.setName("����");
	cout << "������ " << p.getName() << endl;

	//��������
	p.setAge(50);
	cout << "���䣺 " << p.getAge() << endl;

	//��������
	p.setLover("�Ծ�");
	//cout << "���ˣ� " << p.m_Lover << endl;  //ֻд���ԣ������Զ�ȡ

	system("pause");

	return 0;
}
```









**��ϰ����1�������������**

�����������(Cube)

������������������

�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�



![1545533548532](assets/1545533548532.png)











**��ϰ����2�����Բ�Ĺ�ϵ**

���һ��Բ���ࣨCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��



![1545533829184](assets/1545533829184.png)







### 4.2 ����ĳ�ʼ��������



*  ������������ĵ��Ӳ�Ʒ���������г������ã���ĳһ�����ǲ���ʱ��Ҳ��ɾ��һЩ�Լ���Ϣ���ݱ�֤��ȫ
*  C++�е����������Դ�����ÿ������Ҳ�����г�ʼ�����Լ� ��������ǰ���������ݵ����á�





#### 4.2.1 ���캯������������

�����**��ʼ��������**Ҳ�������ǳ���Ҫ�İ�ȫ����

?	һ��������߱���û�г�ʼ״̬������ʹ�ú����δ֪

?	ͬ����ʹ����һ������������û�м�ʱ����Ҳ�����һ���İ�ȫ����



c++������**���캯��**��**��������**����������⣬�������������ᱻ�������Զ����ã���ɶ����ʼ������������

����ĳ�ʼ�����������Ǳ�����ǿ��Ҫ�����������飬������**���ǲ��ṩ��������������������ṩ**

**�������ṩ�Ĺ��캯�������������ǿ�ʵ�֡�**



* ���캯������Ҫ�������ڴ�������ʱΪ����ĳ�Ա���Ը�ֵ�����캯���ɱ������Զ����ã������ֶ����á�
* ������������Ҫ�������ڶ���**����ǰ**ϵͳ�Զ����ã�ִ��һЩ��������





**���캯���﷨��**`����(){}`

1. ���캯����û�з���ֵҲ��дvoid
2. ����������������ͬ
3. ���캯�������в�������˿��Է�������
4. �����ڵ��ö���ʱ����Զ����ù��죬�����ֶ�����,����ֻ�����һ��





**���������﷨��** `~����(){}`

1. ����������û�з���ֵҲ��дvoid
2. ����������������ͬ,������ǰ���Ϸ���  ~
3. ���������������в�������˲����Է�������
4. �����ڶ�������ǰ���Զ����������������ֶ�����,����ֻ�����һ��





```C++
class Person
{
public:
	//���캯��
	Person()
	{
		cout << "Person�Ĺ��캯������" << endl;
	}
	//��������
	~Person()
	{
		cout << "Person��������������" << endl;
	}

};

void test01()
{
	Person p;
}

int main() {
	
	test01();

	system("pause");

	return 0;
}
```











#### 4.2.2 ���캯���ķ��༰����

���ַ��෽ʽ��

?	��������Ϊ�� �вι�����޲ι���

?	�����ͷ�Ϊ�� ��ͨ����Ϳ�������

���ֵ��÷�ʽ��

?	���ŷ�

?	��ʾ��

?	��ʽת����



**ʾ����**

```C++
//1�����캯������
// ���ղ��������Ϊ �вκ��޲ι���   �޲��ֳ�ΪĬ�Ϲ��캯��
// �������ͷ����Ϊ ��ͨ����Ϳ�������

class Person {
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Person() {
		cout << "�޲ι��캯��!" << endl;
	}
	//�вι��캯��
	Person(int a) {
		age = a;
		cout << "�вι��캯��!" << endl;
	}
	//�������캯��
	Person(const Person& p) {
		age = p.age;
		cout << "�������캯��!" << endl;
	}
	//��������
	~Person() {
		cout << "��������!" << endl;
	}
public:
	int age;
};

//2�����캯���ĵ���
//�����޲ι��캯��
void test01() {
	Person p; //�����޲ι��캯��
}

//�����вεĹ��캯��
void test02() {

	//2.1  ���ŷ�������
	Person p1(10);
	//ע��1�������޲ι��캯�����ܼ����ţ�������˱�������Ϊ����һ����������
	//Person p2();

	//2.2 ��ʽ��
	Person p2 = Person(10); 
	Person p3 = Person(p2);
	//Person(10)����д������������  ��ǰ�н���֮����������

	//2.3 ��ʽת����
	Person p4 = 10; // Person p4 = Person(10); 
	Person p5 = p4; // Person p5 = Person(p4); 

	//ע��2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ�������
	//Person p5(p4);
}

int main() {

	test01();
	//test02();

	system("pause");

	return 0;
}
```









#### 4.2.3 �������캯������ʱ��



C++�п������캯������ʱ��ͨ�����������

* ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
* ֵ���ݵķ�ʽ������������ֵ
* ��ֵ��ʽ���ؾֲ�����



**ʾ����**

```C++
class Person {
public:
	Person() {
		cout << "�޲ι��캯��!" << endl;
		mAge = 0;
	}
	Person(int age) {
		cout << "�вι��캯��!" << endl;
		mAge = age;
	}
	Person(const Person& p) {
		cout << "�������캯��!" << endl;
		mAge = p.mAge;
	}
	//�����������ͷ��ڴ�֮ǰ����
	~Person() {
		cout << "��������!" << endl;
	}
public:
	int mAge;
};

//1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01() {

	Person man(100); //p�����Ѿ��������
	Person newman(man); //���ÿ������캯��
	Person newman2 = man; //��������

	//Person newman3;
	//newman3 = man; //���ǵ��ÿ������캯������ֵ����
}

//2. ֵ���ݵķ�ʽ������������ֵ
//�൱��Person p1 = p;
void doWork(Person p1) {}
void test02() {
	Person p; //�޲ι��캯��
	doWork(p);
}

//3. ��ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;
	cout << (int *)&p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int *)&p << endl;
}


int main() {

	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}
```





#### 4.2.4 ���캯�����ù���

Ĭ������£�c++���������ٸ�һ�������3������

1��Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)

2��Ĭ����������(�޲Σ�������Ϊ��)

3��Ĭ�Ͽ������캯���������Խ���ֵ����



���캯�����ù������£�

* ����û������вι��캯����c++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������


* ����û����忽�����캯����c++�������ṩ�������캯��



ʾ����

```C++
class Person {
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Person() {
		cout << "�޲ι��캯��!" << endl;
	}
	//�вι��캯��
	Person(int a) {
		age = a;
		cout << "�вι��캯��!" << endl;
	}
	//�������캯��
	Person(const Person& p) {
		age = p.age;
		cout << "�������캯��!" << endl;
	}
	//��������
	~Person() {
		cout << "��������!" << endl;
	}
public:
	int age;
};

void test01()
{
	Person p1(18);
	//�����д�������죬���������Զ���ӿ������죬������ǳ��������
	Person p2(p1);

	cout << "p2������Ϊ�� " << p2.age << endl;
}

void test02()
{
	//����û��ṩ�вι��죬�����������ṩĬ�Ϲ��죬���ṩ��������
	Person p1; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
	Person p2(10); //�û��ṩ���в�
	Person p3(p2); //��ʱ����û�û���ṩ�������죬���������ṩ

	//����û��ṩ�������죬�����������ṩ�������캯��
	Person p4; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
	Person p5(10); //��ʱ����û��Լ�û���ṩ�вΣ������
	Person p6(p5); //�û��Լ��ṩ��������
}

int main() {

	test01();

	system("pause");

	return 0;
}
```









#### 4.2.5 �����ǳ����



��ǳ���������Ծ������⣬Ҳ�ǳ�����һ����



ǳ�������򵥵ĸ�ֵ��������



������ڶ�����������ռ䣬���п�������



**ʾ����**

```C++
class Person {
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Person() {
		cout << "�޲ι��캯��!" << endl;
	}
	//�вι��캯��
	Person(int age ,int height) {
		
		cout << "�вι��캯��!" << endl;

		m_age = age;
		m_height = new int(height);
		
	}
	//�������캯��  
	Person(const Person& p) {
		cout << "�������캯��!" << endl;
		//�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
		m_age = p.m_age;
		m_height = new int(*p.m_height);
		
	}

	//��������
	~Person() {
		cout << "��������!" << endl;
		if (m_height != NULL)
		{
			delete m_height;
		}
	}
public:
	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18, 180);

	Person p2(p1);

	cout << "p1�����䣺 " << p1.m_age << " ��ߣ� " << *p1.m_height << endl;

	cout << "p2�����䣺 " << p2.m_age << " ��ߣ� " << *p2.m_height << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

> �ܽ᣺����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������









#### 4.2.6 ��ʼ���б�



**���ã�**

C++�ṩ�˳�ʼ���б��﷨��������ʼ������



**�﷨��**`���캯��()������1(ֵ1),����2��ֵ2��... {}`



**ʾ����**

```C++
class Person {
public:

	////��ͳ��ʽ��ʼ��
	//Person(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//��ʼ���б�ʽ��ʼ��
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
	void PrintPerson() {
		cout << "mA:" << m_A << endl;
		cout << "mB:" << m_B << endl;
		cout << "mC:" << m_C << endl;
	}
private:
	int m_A;
	int m_B;
	int m_C;
};

int main() {

	Person p(1, 2, 3);
	p.PrintPerson();


	system("pause");

	return 0;
}
```





#### 4.2.7 �������Ϊ���Ա



C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ �����Ա



���磺

```C++
class A {}
class B
{
    A a��
}
```



B�����ж���A��Ϊ��Ա��AΪ�����Ա



��ô������B����ʱ��A��B�Ĺ����������˳����˭��˭��



**ʾ����**

```C++
class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone����" << endl;
	}

	~Phone()
	{
		cout << "Phone����" << endl;
	}

	string m_PhoneName;

};


class Person
{
public:

	//��ʼ���б���Ը��߱�����������һ�����캯��
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person����" << endl;
	}

	~Person()
	{
		cout << "Person����" << endl;
	}

	void playGame()
	{
		cout << m_Name << " ʹ��" << m_Phone.m_PhoneName << " ���ֻ�! " << endl;
	}

	string m_Name;
	Phone m_Phone;

};
void test01()
{
	//�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
	//�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//����˳���빹���෴
	Person p("����" , "ƻ��X");
	p.playGame();

}


int main() {

	test01();

	system("pause");

	return 0;
}
```











#### 4.2.8 ��̬��Ա

��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա

��̬��Ա��Ϊ��



*  ��̬��Ա����
   *  ���ж�����ͬһ������
   *  �ڱ���׶η����ڴ�
   *  ���������������ʼ��
*  ��̬��Ա����
   *  ���ж�����ͬһ������
   *  ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����







**ʾ��1 ��**��̬��Ա����

```C++
class Person
{
	
public:

	static int m_A; //��̬��Ա����

	//��̬��Ա�����ص㣺
	//1 �ڱ���׶η����ڴ�
	//2 ���������������ʼ��
	//3 ���ж�����ͬһ������

private:
	static int m_B; //��̬��Ա����Ҳ���з���Ȩ�޵�
};
int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	//��̬��Ա�������ַ��ʷ�ʽ

	//1��ͨ������
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //����ͬһ������
	cout << "p2.m_A = " << p2.m_A << endl;

	//2��ͨ������
	cout << "m_A = " << Person::m_A << endl;


	//cout << "m_B = " << Person::m_B << endl; //˽��Ȩ�޷��ʲ���
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



**ʾ��2��**��̬��Ա����

```C++
class Person
{

public:

	//��̬��Ա�����ص㣺
	//1 ������һ������
	//2 ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	
	static void func()
	{
		cout << "func����" << endl;
		m_A = 100;
		//m_B = 100; //���󣬲����Է��ʷǾ�̬��Ա����
	}

	static int m_A; //��̬��Ա����
	int m_B; // 
private:

	//��̬��Ա����Ҳ���з���Ȩ�޵�
	static void func2()
	{
		cout << "func2����" << endl;
	}
};
int Person::m_A = 10;


void test01()
{
	//��̬��Ա�������ַ��ʷ�ʽ

	//1��ͨ������
	Person p1;
	p1.func();

	//2��ͨ������
	Person::func();


	//Person::func2(); //˽��Ȩ�޷��ʲ���
}

int main() {

	test01();

	system("pause");

	return 0;
}
```









### 4.3 C++����ģ�ͺ�thisָ��



#### 4.3.1 ��Ա�����ͳ�Ա�����ֿ��洢



��C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢

ֻ�зǾ�̬��Ա������������Ķ�����



```C++
class Person {
public:
	Person() {
		mA = 0;
	}
	//�Ǿ�̬��Ա����ռ����ռ�
	int mA;
	//��̬��Ա������ռ����ռ�
	static int mB; 
	//����Ҳ��ռ����ռ䣬���к�������һ������ʵ��
	void func() {
		cout << "mA:" << this->mA << endl;
	}
	//��̬��Ա����Ҳ��ռ����ռ�
	static void sfunc() {
	}
};

int main() {

	cout << sizeof(Person) << endl;

	system("pause");

	return 0;
}
```







#### 4.3.2 thisָ�����

ͨ��4.3.1����֪����C++�г�Ա�����ͳ�Ա�����Ƿֿ��洢��

ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����

��ô�����ǣ���һ���������������Ǹ���������Լ����أ�



c++ͨ���ṩ����Ķ���ָ�룬thisָ�룬����������⡣**thisָ��ָ�򱻵��õĳ�Ա���������Ķ���**



thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��

thisָ�벻��Ҫ���壬ֱ��ʹ�ü���



thisָ�����;��

*  ���βκͳ�Ա����ͬ��ʱ������thisָ��������
*  ����ķǾ�̬��Ա�����з��ض�������ʹ��return *this

```C++
class Person
{
public:

	Person(int age)
	{
		//1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
		this->age = age;
	}

	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		//���ض�����
		return *this;
	}

	int age;
};

void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```









#### 4.3.3 ��ָ����ʳ�Ա����



C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��



����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��



**ʾ����**

```C++
//��ָ����ʳ�Ա����
class Person {
public:

	void ShowClassName() {
		cout << "����Person��!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;
	}

public:
	int mAge;
};

void test01()
{
	Person * p = NULL;
	p->ShowClassName(); //��ָ�룬���Ե��ó�Ա����
	p->ShowPerson();  //���������Ա�������õ���thisָ�룬�Ͳ�������
}

int main() {

	test01();

	system("pause");

	return 0;
}
```









#### 4.3.4 const���γ�Ա����



**��������**

* ��Ա�������const�����ǳ�Ϊ�������Ϊ**������**
* �������ڲ������޸ĳ�Ա����
* ��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�



**������**

* ��������ǰ��const�Ƹö���Ϊ������
* ������ֻ�ܵ��ó�����







**ʾ����**

```C++
class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}

	//thisָ��ı�����һ��ָ�볣����ָ���ָ�򲻿��޸�
	//�������ָ��ָ���ֵҲ�������޸ģ���Ҫ����������
	void ShowPerson() const {
		//const Type* const pointer;
		//this = NULL; //�����޸�ָ���ָ�� Person* const this;
		//this->mA = 100; //����thisָ��ָ��Ķ���������ǿ����޸ĵ�

		//const���γ�Ա��������ʾָ��ָ����ڴ�ռ�����ݲ����޸ģ�����mutable���εı���
		this->m_B = 100;
	}

	void MyFunc() const {
		//mA = 10000;
	}

public:
	int m_A;
	mutable int m_B; //���޸� �ɱ��
};


//const���ζ���  ������
void test01() {

	const Person person; //��������  
	cout << person.m_A << endl;
	//person.mA = 100; //���������޸ĳ�Ա������ֵ,���ǿ��Է���
	person.m_B = 100; //���ǳ���������޸�mutable���γ�Ա����

	//��������ʳ�Ա����
	person.MyFunc(); //�������ܵ���const�ĺ���

}

int main() {

	test01();

	system("pause");

	return 0;
}
```








### 4.4 ��Ԫ



��������ļ��п���(Public)�����������(Private)

�����������Ŀ��˶����Խ�ȥ���������������˽�еģ�Ҳ����˵ֻ�����ܽ�ȥ

�����أ���Ҳ����������ĺù��ۺû��ѽ�ȥ��



�ڳ������Щ˽������ Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ�ļ���



��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա



��Ԫ�Ĺؼ���Ϊ  ==friend==



��Ԫ������ʵ��

* ȫ�ֺ�������Ԫ
* ������Ԫ
* ��Ա��������Ԫ





#### 4.4.1 ȫ�ֺ�������Ԫ

```C++
class Building
{
	//���߱����� goodGayȫ�ֺ��� �� Building��ĺ����ѣ����Է������е�˽������
	friend void goodGay(Building * building);

public:

	Building()
	{
		this->m_SittingRoom = "����";
		this->m_BedRoom = "����";
	}


public:
	string m_SittingRoom; //����

private:
	string m_BedRoom; //����
};


void goodGay(Building * building)
{
	cout << "�û������ڷ��ʣ� " << building->m_SittingRoom << endl;
	cout << "�û������ڷ��ʣ� " << building->m_BedRoom << endl;
}


void test01()
{
	Building b;
	goodGay(&b);
}

int main(){

	test01();

	system("pause");
	return 0;
}
```



#### 4.4.2 ������Ԫ



```C++
class Building;
class goodGay
{
public:

	goodGay();
	void visit();

private:
	Building *building;
};


class Building
{
	//���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend class goodGay;

public:
	Building();

public:
	string m_SittingRoom; //����
private:
	string m_BedRoom;//����
};

Building::Building()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}

goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
}

void test01()
{
	goodGay gg;
	gg.visit();

}

int main(){

	test01();

	system("pause");
	return 0;
}
```





#### 4.4.3 ��Ա��������Ԫ



```C++

class Building;
class goodGay
{
public:

	goodGay();
	void visit(); //ֻ��visit������ΪBuilding�ĺ����ѣ����Է�����Building��˽������
	void visit2(); 

private:
	Building *building;
};


class Building
{
	//���߱�����  goodGay���е�visit��Ա���� ��Building�����ѣ����Է���˽������
	friend void goodGay::visit();

public:
	Building();

public:
	string m_SittingRoom; //����
private:
	string m_BedRoom;//����
};

Building::Building()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}

goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	//cout << "�û������ڷ���" << building->m_BedRoom << endl;
}

void test01()
{
	goodGay  gg;
	gg.visit();

}

int main(){
    
	test01();

	system("pause");
	return 0;
}
```









### 4.5 ���������



��������ظ�������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������



#### 4.5.1 �Ӻ����������



���ã�ʵ�������Զ�������������ӵ�����



```C++
class Person {
public:
	Person() {};
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//��Ա����ʵ�� + �����������
	Person operator+(const Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}


public:
	int m_A;
	int m_B;
};

//ȫ�ֺ���ʵ�� + �����������
//Person operator+(const Person& p1, const Person& p2) {
//	Person temp(0, 0);
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

//��������� ���Է����������� 
Person operator+(const Person& p2, int val)  
{
	Person temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	return temp;
}

void test() {

	Person p1(10, 10);
	Person p2(20, 20);

	//��Ա������ʽ
	Person p3 = p2 + p1;  //�൱�� p2.operaor+(p1)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;


	Person p4 = p3 + 10; //�൱�� operator+(p3,10)
	cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

}

int main() {

	test();

	system("pause");

	return 0;
}
```



> �ܽ�1���������õ��������͵ı��ʽ�ĵ�������ǲ����ܸı��

> �ܽ�2����Ҫ�������������







#### 4.5.2 �������������



���ã���������Զ�����������



```C++
class Person {
	friend ostream& operator<<(ostream& out, Person& p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//��Ա���� ʵ�ֲ���  p << cout ����������Ҫ��Ч��
	//void operator<<(Person& p){
	//}

private:
	int m_A;
	int m_B;
};

//ȫ�ֺ���ʵ����������
//ostream����ֻ����һ��
ostream& operator<<(ostream& out, Person& p) {
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;
}

void test() {

	Person p1(10, 20);

	cout << p1 << "hello world" << endl; //��ʽ���
}

int main() {

	test();

	system("pause");

	return 0;
}
```



> �ܽ᣺������������������Ԫ����ʵ������Զ�����������













#### 4.5.3 �������������



���ã� ͨ�����ص����������ʵ���Լ�����������



```C++

class MyInteger {

	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() {
		m_Num = 0;
	}
	//ǰ��++
	MyInteger& operator++() {
		//��++
		m_Num++;
		//�ٷ���
		return *this;
	}

	//����++
	MyInteger operator++(int) {
		//�ȷ���
		MyInteger temp = *this; //��¼��ǰ�����ֵ��Ȼ���ñ����ֵ��1�����Ƿ��ص�����ǰ��ֵ���ﵽ�ȷ��غ�++��
		m_Num++;
		return temp;
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}


//ǰ��++ ��++ �ٷ���
void test01() {
	MyInteger myInt;
	cout << ++myInt << endl;
	cout << myInt << endl;
}

//����++ �ȷ��� ��++
void test02() {

	MyInteger myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main() {

	test01();
	//test02();

	system("pause");

	return 0;
}
```



> �ܽ᣺ ǰ�õ����������ã����õ�������ֵ













#### 4.5.4 ��ֵ���������



c++���������ٸ�һ�������4������

1. Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
2. Ĭ����������(�޲Σ�������Ϊ��)
3. Ĭ�Ͽ������캯���������Խ���ֵ����
4. ��ֵ����� operator=, �����Խ���ֵ����





�������������ָ�����������ֵ����ʱҲ�������ǳ��������





**ʾ����**

```C++
class Person
{
public:

	Person(int age)
	{
		//���������ݿ��ٵ�����
		m_Age = new int(age);
	}

	//���ظ�ֵ����� 
	Person& operator=(Person &p)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//�������ṩ�Ĵ�����ǳ����
		//m_Age = p.m_Age;

		//�ṩ��� ���ǳ����������
		m_Age = new int(*p.m_Age);

		//��������
		return *this;
	}


	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//�����ָ��
	int *m_Age;

};


void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1; //��ֵ����

	cout << "p1������Ϊ��" << *p1.m_Age << endl;

	cout << "p2������Ϊ��" << *p2.m_Age << endl;

	cout << "p3������Ϊ��" << *p3.m_Age << endl;
}

int main() {

	test01();

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//c = b = a;
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;

	system("pause");

	return 0;
}
```









#### 4.5.5 ��ϵ���������



**���ã�**���ع�ϵ������������������Զ������Ͷ�����жԱȲ���



**ʾ����**

```C++
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	};

	bool operator==(Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	//int a = 0;
	//int b = 0;

	Person a("�����", 18);
	Person b("�����", 18);

	if (a == b)
	{
		cout << "a��b���" << endl;
	}
	else
	{
		cout << "a��b�����" << endl;
	}

	if (a != b)
	{
		cout << "a��b�����" << endl;
	}
	else
	{
		cout << "a��b���" << endl;
	}
}


int main() {

	test01();

	system("pause");

	return 0;
}
```





#### 4.5.6 �����������������



* ������������� ()  Ҳ��������
* �������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
* �º���û�й̶�д�����ǳ����



**ʾ����**

```C++
class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}

};
void test01()
{
	//���صģ��������� Ҳ��Ϊ�º���
	MyPrint myFunc;
	myFunc("hello world");
}


class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//�����������  
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}
```









### 4.6  �̳�

**�̳������������������֮һ**

��Щ������֮���������Ĺ�ϵ��������ͼ�У�

![1544861202252](assets/1544861202252.png)

���Ƿ��֣�������Щ��ʱ���¼���ĳ�Ա����ӵ����һ���Ĺ��ԣ������Լ������ԡ�

���ʱ�����ǾͿ��Կ������ü̳еļ����������ظ�����



#### 4.6.1 �̳еĻ����﷨



�������ǿ����ܶ���վ�У����й�����ͷ���������ĵײ�����������������б�ֻ���������ݲ�ͬ

���������Ƿֱ�������ͨд���ͼ̳е�д����ʵ����ҳ�е����ݣ���һ�¼̳д��ڵ������Լ��ô�



**��ͨʵ�֣�**

```C++
//Javaҳ��
class Java 
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
	void content()
	{
		cout << "JAVAѧ����Ƶ" << endl;
	}
};
//Pythonҳ��
class Python
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};
//C++ҳ��
class CPP 
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};

void test01()
{
	//Javaҳ��
	cout << "Java������Ƶҳ�����£� " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Pythonҳ��
	cout << "Python������Ƶҳ�����£� " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++ҳ��
	cout << "C++������Ƶҳ�����£� " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();

}

int main() {

	test01();

	system("pause");

	return 0;
}
```



**�̳�ʵ�֣�**

```C++
//����ҳ��
class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}

	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}

};

//Javaҳ��
class Java : public BasePage
{
public:
	void content()
	{
		cout << "JAVAѧ����Ƶ" << endl;
	}
};
//Pythonҳ��
class Python : public BasePage
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};
//C++ҳ��
class CPP : public BasePage
{
public:
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};

void test01()
{
	//Javaҳ��
	cout << "Java������Ƶҳ�����£� " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Pythonҳ��
	cout << "Python������Ƶҳ�����£� " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++ҳ��
	cout << "C++������Ƶҳ�����£� " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();


}

int main() {

	test01();

	system("pause");

	return 0;
}
```



**�ܽ᣺**

�̳еĺô���==���Լ����ظ��Ĵ���==

class A : public B; 

A ���Ϊ���� �� ������

B ���Ϊ���� �� ����



**�������еĳ�Ա���������󲿷�**��

һ���Ǵӻ���̳й����ģ�һ�����Լ����ӵĳ�Ա��

�ӻ���̳й������ı����乲�ԣ��������ĳ�Ա����������ԡ�









#### 4.6.2 �̳з�ʽ



�̳е��﷨��`class ���� : �̳з�ʽ  ����`



**�̳з�ʽһ�������֣�**

* �����̳�
* �����̳�
* ˽�м̳�





![img](assets/clip_image002.png)





**ʾ����**

```C++
class Base1
{
public: 
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//�����̳�
class Son1 :public Base1
{
public:
	void func()
	{
		m_A; //�ɷ��� publicȨ��
		m_B; //�ɷ��� protectedȨ��
		//m_C; //���ɷ���
	}
};

void myClass()
{
	Son1 s1;
	s1.m_A; //������ֻ�ܷ��ʵ�����Ȩ��
}

//�����̳�
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2:protected Base2
{
public:
	void func()
	{
		m_A; //�ɷ��� protectedȨ��
		m_B; //�ɷ��� protectedȨ��
		//m_C; //���ɷ���
	}
};
void myClass2()
{
	Son2 s;
	//s.m_A; //���ɷ���
}

//˽�м̳�
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3:private Base3
{
public:
	void func()
	{
		m_A; //�ɷ��� privateȨ��
		m_B; //�ɷ��� privateȨ��
		//m_C; //���ɷ���
	}
};
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//Son3��˽�м̳У����Լ̳�Son3��������GrandSon3�ж��޷����ʵ�
		//m_A;
		//m_B;
		//m_C;
	}
};
```









#### 4.6.3 �̳��еĶ���ģ��



**���⣺**�Ӹ���̳й����ĳ�Ա����Щ������������У�



**ʾ����**

```C++
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //˽�г�Աֻ�Ǳ������ˣ����ǻ��ǻ�̳���ȥ
};

//�����̳�
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```





���ù��߲鿴��



![1545881904150](assets/1545881904150.png)



�򿪹��ߴ��ں󣬶�λ����ǰCPP�ļ����̷�

Ȼ�����룺 cl /d1 reportSingleClassLayout�鿴������   �����ļ���



Ч������ͼ��



![1545882158050](assets/1545882158050.png)



> ���ۣ� ������˽�г�ԱҲ�Ǳ�����̳���ȥ�ˣ�ֻ���ɱ����������غ���ʲ���



















#### 4.6.4 �̳��й��������˳��



����̳и���󣬵������������Ҳ����ø���Ĺ��캯��



���⣺���������Ĺ��������˳����˭��˭��



**ʾ����**

```C++
class Base 
{
public:
	Base()
	{
		cout << "Base���캯��!" << endl;
	}
	~Base()
	{
		cout << "Base��������!" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son���캯��!" << endl;
	}
	~Son()
	{
		cout << "Son��������!" << endl;
	}

};


void test01()
{
	//�̳��� �ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴
	Son s;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



> �ܽ᣺�̳��� �ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴











#### 4.6.5 �̳�ͬ����Ա����ʽ



���⣺�������븸�����ͬ���ĳ�Ա�����ͨ��������󣬷��ʵ����������ͬ���������أ�



* ��������ͬ����Ա   ֱ�ӷ��ʼ���
* ���ʸ���ͬ����Ա   ��Ҫ��������



**ʾ����**

```C++
class Base {
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func()����" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)����" << endl;
	}

public:
	int m_A;
};


class Son : public Base {
public:
	Son()
	{
		m_A = 200;
	}

	//�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
	//�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
	void func()
	{
		cout << "Son - func()����" << endl;
	}
public:
	int m_A;
};

void test01()
{
	Son s;

	cout << "Son�µ�m_A = " << s.m_A << endl;
	cout << "Base�µ�m_A = " << s.Base::m_A << endl;

	s.func();
	s.Base::func();
	s.Base::func(10);

}
int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}
```

�ܽ᣺

1. ����������ֱ�ӷ��ʵ�������ͬ����Ա
2. ����������������Է��ʵ�����ͬ����Ա
3. �������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������













#### 4.6.6 �̳�ͬ����̬��Ա����ʽ



���⣺�̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�



��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��



- ��������ͬ����Ա   ֱ�ӷ��ʼ���
- ���ʸ���ͬ����Ա   ��Ҫ��������



**ʾ����**

```C++
class Base {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

	static int m_A;
};

int Base::m_A = 100;

class Son : public Base {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//ͬ����Ա����
void test01()
{
	//ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	Son s;
	cout << "Son  �� m_A = " << s.m_A << endl;
	cout << "Base �� m_A = " << s.Base::m_A << endl;

	//ͨ����������
	cout << "ͨ���������ʣ� " << endl;
	cout << "Son  �� m_A = " << Son::m_A << endl;
	cout << "Base �� m_A = " << Son::Base::m_A << endl;
}

//ͬ����Ա����
void test02()
{
	//ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	Son s;
	s.func();
	s.Base::func();

	cout << "ͨ���������ʣ� " << endl;
	Son::func();
	Son::Base::func();
	//����ͬ������������ص�����������ͬ����Ա��������Ҫ�������������
	Son::Base::func(100);
}
int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}
```

> �ܽ᣺ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ��ͨ������ �� ͨ��������













#### 4.6.7 ��̳��﷨



C++����**һ����̳ж����**



�﷨��` class ���� ���̳з�ʽ ����1 �� �̳з�ʽ ����2...`



��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������



**C++ʵ�ʿ����в������ö�̳�**







**ʾ����**

```C++
class Base1 {
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base2 {
public:
	Base2()
	{
		m_A = 200;  //��ʼ��m_B ��������⣬���Ǹ�ΪmA�ͻ���ֲ���ȷ
	}
public:
	int m_A;
};

//�﷨��class ���ࣺ�̳з�ʽ ����1 ���̳з�ʽ ����2 
class Son : public Base2, public Base1 
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};


//��̳����ײ�����Աͬ�������
//ͨ��ʹ������������������ֵ�����һ������ĳ�Ա
void test01()
{
	Son s;
	cout << "sizeof Son = " << sizeof(s) << endl;
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



> �ܽ᣺ ��̳�����������г�����ͬ�����������ʹ��ʱ��Ҫ��������











#### 4.6.8 ���μ̳�



**���μ̳и��**

?	����������̳�ͬһ������

?	����ĳ����ͬʱ�̳�������������

?	���ּ̳б���Ϊ���μ̳У�������ʯ�̳�



**���͵����μ̳а�����**



![IMG_256](assets/clip_image002.jpg)



**���μ̳����⣺**



1.     ��̳��˶�������ݣ���ͬ���̳��˶�������ݣ���������ʹ������ʱ���ͻ���������ԡ�

2. ������̳��Զ�������ݼ̳������ݣ���ʵ����Ӧ������������������ֻ��Ҫһ�ݾͿ��ԡ�



**ʾ����**

```C++
class Animal
{
public:
	int m_Age;
};

//�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳�
//��ʱ�����ĸ���Animal��Ϊ�����
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}


int main() {

	test01();

	system("pause");

	return 0;
}
```



�ܽ᣺

* ���μ̳д�������Ҫ����������̳�������ͬ�����ݣ�������Դ�˷��Լ���������
* ������̳п��Խ�����μ̳�����



















### 4.7  ��̬

#### 4.7.1 ��̬�Ļ�������



**��̬��C++���������������֮һ**

��̬��Ϊ����

* ��̬��̬: �������� �� ������������ھ�̬��̬�����ú�����
* ��̬��̬: ��������麯��ʵ������ʱ��̬



��̬��̬�Ͷ�̬��̬����

* ��̬��̬�ĺ�����ַ���  -  ����׶�ȷ��������ַ
* ��̬��̬�ĺ�����ַ���  -  ���н׶�ȷ��������ַ



����ͨ���������н����̬



```C++
class Animal
{
public:
	//Speak���������麯��
	//����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:

	void speak()
	{
		cout << "С����˵��" << endl;
	}

};
//����ϣ������ʲô������ô�͵���ʲô����ĺ���
//���������ַ�ڱ���׶ξ���ȷ������ô��̬����
//���������ַ�����н׶β���ȷ�������Ƕ�̬����

void DoSpeak(Animal & animal)
{
	animal.speak();
}
//
//��̬���������� 
//1���м̳й�ϵ
//2��������д�����е��麯��
//��̬ʹ�ã�
//����ָ�������ָ���������

void test01()
{
	Cat cat;
	DoSpeak(cat);


	Dog dog;
	DoSpeak(dog);
}


int main() {

	test01();

	system("pause");

	return 0;
}
```

�ܽ᣺

��̬��������

* �м̳й�ϵ
* ������д�����е��麯��

��̬ʹ������

* ����ָ�������ָ���������

��д����������ֵ����  ������ �����б� ��ȫһ�³�Ϊ��д









#### 4.7.2 ��̬����һ-��������



����������

�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������



��̬���ŵ㣺

* ������֯�ṹ����
* �ɶ���ǿ
* ����ǰ�ںͺ��ڵ���չ�Լ�ά��



**ʾ����**

```C++
//��ͨʵ��
class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
	}
public:
	int m_Num1;
	int m_Num2;
};

void test01()
{
	//��ͨʵ�ֲ���
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}



//��̬ʵ��
//�����������
//��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
class AbstractCalculator
{
public :

	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//�ӷ�������
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

//����������
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//�˷�������
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};


void test02()
{
	//�����ӷ�������
	AbstractCalculator *abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;  //�����˼ǵ�����

	//��������������
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;  

	//�����˷�������
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
```

> �ܽ᣺C++�����ᳫ���ö�̬��Ƴ���ܹ�����Ϊ��̬�ŵ�ܶ�

















#### 4.7.3 ���麯���ͳ�����



�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������



��˿��Խ��麯����Ϊ**���麯��**



���麯���﷨��`virtual ����ֵ���� ������ �������б�= 0 ;`



���������˴��麯���������Ҳ��Ϊ==������==



**�������ص�**��

 * �޷�ʵ��������
 * ���������д�������еĴ��麯��������Ҳ���ڳ�����





**ʾ����**

```C++
class Base
{
public:
	//���麯��
	//����ֻҪ��һ�����麯���ͳ�Ϊ������
	//�������޷�ʵ��������
	//���������д�����еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func() 
	{
		cout << "func����" << endl;
	};
};

void test01()
{
	Base * base = NULL;
	//base = new Base; // ���󣬳������޷�ʵ��������
	base = new Son;
	base->func();
	delete base;//�ǵ�����
}

int main() {

	test01();

	system("pause");

	return 0;
}
```















#### 4.7.4 ��̬������-������Ʒ

**����������**

������Ʒ�Ĵ�������Ϊ����ˮ -  ���� - ���뱭�� - ���븨��



���ö�̬����ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ



![1545985945198](assets/1545985945198.png)



**ʾ����**

```C++
//����������Ʒ
class AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//�涨����
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee : public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "��ũ��ɽȪ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "�����ȵ��뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "����ţ��!" << endl;
	}
};

//������ˮ
class Tea : public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "������ˮ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "����ˮ���뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "�������!" << endl;
	}
};

//ҵ����
void DoWork(AbstractDrinking* drink) {
	drink->MakeDrink();
	delete drink;
}

void test01() {
	DoWork(new Coffee);
	cout << "--------------" << endl;
	DoWork(new Tea);
}


int main() {

	test01();

	system("pause");

	return 0;
}
```



















#### 4.7.5 �������ʹ�������



��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������



�����ʽ���������е�����������Ϊ**������**����**��������**



�������ʹ����������ԣ�

* ���Խ������ָ���ͷ��������
* ����Ҫ�о���ĺ���ʵ��

�������ʹ�����������

* ����Ǵ����������������ڳ����࣬�޷�ʵ��������



�������﷨��

`virtual ~����(){}`

���������﷨��

` virtual ~����() = 0;`

`����::~����(){}`



**ʾ����**

```C++
class Animal {
public:

	Animal()
	{
		cout << "Animal ���캯�����ã�" << endl;
	}
	virtual void Speak() = 0;

	//������������virtual�ؼ��֣��������������
	//virtual ~Animal()
	//{
	//	cout << "Animal�������������ã�" << endl;
	//}


	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal ���������������ã�" << endl;
}

//�Ͱ�����ͨ���麯������һ���������˴���������������Ҳ��һ�������ࡣ���ܹ���ʵ������

class Cat : public Animal {
public:
	Cat(string name)
	{
		cout << "Cat���캯�����ã�" << endl;
		m_Name = new string(name);
	}
	virtual void Speak()
	{
		cout << *m_Name <<  "Сè��˵��!" << endl;
	}
	~Cat()
	{
		cout << "Cat������������!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}

public:
	string *m_Name;
};

void test01()
{
	Animal *animal = new Cat("Tom");
	animal->Speak();

	//ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
	//��ô���������������һ������������
	//���������������������ͨ������ָ���ͷ��������
	delete animal;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



�ܽ᣺

?	1. �������������������������ͨ������ָ���ͷ��������

?	2. ���������û�ж������ݣ����Բ�дΪ��������������

?	3. ӵ�д���������������Ҳ���ڳ�����















#### 4.7.6 ��̬������-������װ



**����������**



������Ҫ��ɲ���Ϊ CPU�����ڼ��㣩���Կ���������ʾ�����ڴ��������ڴ洢��

��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo����

�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�

����ʱ��װ��̨��ͬ�ĵ��Խ��й���





**ʾ����**

```C++
#include<iostream>
using namespace std;

//����CPU��
class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};

//�����Կ���
class VideoCard
{
public:
	//�������ʾ����
	virtual void display() = 0;
};

//�����ڴ�����
class Memory
{
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU * cpu, VideoCard * vc, Memory * mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	//�ṩ�����ĺ���
	void work()
	{
		//������������������ýӿ�
		m_cpu->calculate();

		m_vc->display();

		m_mem->storage();
	}

	//�ṩ�������� �ͷ�3���������
	~Computer()
	{

		//�ͷ�CPU���
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		//�ͷ��Կ����
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}

		//�ͷ��ڴ������
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

private:

	CPU * m_cpu; //CPU�����ָ��
	VideoCard * m_vc; //�Կ����ָ��
	Memory * m_mem; //�ڴ������ָ��
};

//���峧��
//Intel����
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};

//Lenovo����
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ�����ˣ�" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};


void test01()
{
	//��һ̨�������
	CPU * intelCpu = new IntelCPU;
	VideoCard * intelCard = new IntelVideoCard;
	Memory * intelMem = new IntelMemory;

	cout << "��һ̨���Կ�ʼ������" << endl;
	//������һ̨����
	Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;

	cout << "-----------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	//�ڶ�̨������װ
	Computer * computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);;
	computer2->work();
	delete computer2;

	cout << "-----------------------" << endl;
	cout << "����̨���Կ�ʼ������" << endl;
	//����̨������װ
	Computer * computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);;
	computer3->work();
	delete computer3;

}
```













## 5 �ļ�����



��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�

ͨ��**�ļ����Խ����ݳ־û�**

C++�ж��ļ�������Ҫ����ͷ�ļ� ==&lt; fstream &gt;==



�ļ����ͷ�Ϊ���֣�

1. **�ı��ļ�**     -  �ļ����ı���**ASCII��**��ʽ�洢�ڼ������
2. **�������ļ�** -  �ļ����ı���**������**��ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������



�����ļ���������:

1. ofstream��д����
2. ifstream�� ������
3. fstream �� ��д����



### 5.1�ı��ļ�

#### 5.1.1д�ļ�

   д�ļ��������£�

1. ����ͷ�ļ�   

     \#include <fstream\>

2. ����������  

   ofstream ofs;

3. ���ļ�

   ofs.open("�ļ�·��",�򿪷�ʽ);

4. д����

   ofs << "д�������";

5. �ر��ļ�

   ofs.close();

   ?

�ļ��򿪷�ʽ��

| �򿪷�ʽ    | ����                       |
| ----------- | -------------------------- |
| ios::in     | Ϊ���ļ������ļ�         |
| ios::out    | Ϊд�ļ������ļ�         |
| ios::ate    | ��ʼλ�ã��ļ�β           |
| ios::app    | ׷�ӷ�ʽд�ļ�             |
| ios::trunc  | ����ļ�������ɾ�����ٴ��� |
| ios::binary | �����Ʒ�ʽ                 |

**ע�⣺** �ļ��򿪷�ʽ�������ʹ�ã�����|������

**���磺**�ö����Ʒ�ʽд�ļ� `ios::binary |  ios:: out`





**ʾ����**

```C++
#include <fstream>

void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);

	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

�ܽ᣺

* �ļ������������ͷ�ļ� fstream
* ���ļ��������� ofstream  ������fstream��
* ���ļ�ʱ����Ҫָ�������ļ���·�����Լ��򿪷�ʽ
* ����<<�������ļ���д����
* ������ϣ�Ҫ�ر��ļ�

















#### 5.1.2���ļ�



���ļ���д�ļ��������ƣ����Ƕ�ȡ��ʽ����ڱȽ϶�



���ļ��������£�

1. ����ͷ�ļ�   

     \#include <fstream\>

2. ����������  

   ifstream ifs;

3. ���ļ����ж��ļ��Ƿ�򿪳ɹ�

   ifs.open("�ļ�·��",�򿪷�ʽ);

4. ������

   ���ַ�ʽ��ȡ

5. �ر��ļ�

   ifs.close();



**ʾ����**

```C++
#include <fstream>
#include <string>
void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ַ�ʽ
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//������
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close();


}

int main() {

	test01();

	system("pause");

	return 0;
}
```

�ܽ᣺

- ���ļ��������� ifstream  ������fstream��
- ����is_open���������ж��ļ��Ƿ�򿪳ɹ�
- close �ر��ļ� 















### 5.2 �������ļ�

�Զ����Ƶķ�ʽ���ļ����ж�д����

�򿪷�ʽҪָ��Ϊ ==ios::binary==



#### 5.2.1 д�ļ�

�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write

����ԭ�� ��`ostream& write(const char * buffer,int len);`

�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���



**ʾ����**

```C++
#include <fstream>
#include <string>

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//�������ļ�  д�ļ�
void test01()
{
	//1������ͷ�ļ�

	//2���������������
	ofstream ofs("person.txt", ios::out | ios::binary);
	
	//3�����ļ�
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"����"  , 18};

	//4��д�ļ�
	ofs.write((const char *)&p, sizeof(p));

	//5���ر��ļ�
	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}
```

�ܽ᣺

* �ļ���������� ����ͨ��write�������Զ����Ʒ�ʽд����











#### 5.2.2 ���ļ�

�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read

����ԭ�ͣ�`istream& read(char *buffer,int len);`

�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���

ʾ����

```C++
#include <fstream>
#include <string>

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test01()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	Person p;
	ifs.read((char *)&p, sizeof(p));

	cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
```



- �ļ����������� ����ͨ��read�������Զ����Ʒ�ʽ������

