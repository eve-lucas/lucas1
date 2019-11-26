///////ͷ�ļ������Զ������ �ṹ�� ������ʵ�ֺ��������뺯��������룩
//����һ����ϵ�˽ṹ�� struct info;
//ͨѶ¼����˵���Ϣ�� 1������char[] 2���Ա�char[]3���绰����char[],������int[]����Ϊ���η�Χ���� 4����ַchar[] 5������int
//��Ҫ�����������  1��NAME_MAX 2��GENDER_MAX  3��TELE_MAX 4��ADDR_MAX  5��int �������ֱ�Ӹ�ֵ
//����һ��info������Ϣ���;ͺ�
//����һ����ϵ��ͨѶ¼���൱��һ����¼��
//���Դ洢��ͨѶ¼�˸��� 1�������˵ĸ�����info data[]; �ִ洢�ĸ��� int size;
//��Ҫ����������� 1��MAX;
//����һ��ͨѶ¼�����ͣ��ڼ�һ��ָ�����ͣ��ڽ���ͨѶ¼��ѯ�洢ʱ����Ҫ��ͨѶ¼�ṹ���ָ��

//ͨ��¼����
//1����ʼ��ͨѶ��Init 2��������ϵ��Add 3��ɾ����ϵ��Del4��Ѱ����ϵ�� Search5��������ϵ��Modify
#pragma once;
#define NAME_MAX 100 //����ĺ궼���ӷֺ�
#define GENDER_MAX 20
#define TELE_MAX 20
#define ADDR_MAX 100
#define MAX 200//ͨѶ¼��С   ����ͨѶ¼�Ĵ�С���ǿ����ö��� �����٣����Կ�����malloc����
#define DEFAULT 1
typedef struct info  //�ṹ�����Ͷ��壬ʹ��typedef
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TELE_MAX];
	char add[ADDR_MAX];
}info;
//��̬�洢
//typedef struct Contact
//{
//	info data[MAX];//��ͨѶ¼��������ͨѶ¼��  ͨѶ¼������
//	int size;//��ǰ������Ϣ����
//}Contact, *pContact;//����ṹ��ָ�����ڽ���ͨѶ¼�仯ʱ����Ҫ����ָ��
////��̬�洢
typedef struct Contact
{
	info *data;//����һ��ͨѶ¼ָ�룬���Ը������ٿռ�
	int size;
	int capacity;//��¼��ǰ����
}Contact,*pContact;



//��ͨѶ¼���� һ���ӿ�
void Initcontact(pContact pc);// �������� ����+������ �ṹ��ָ������+���� int add(int x);int add(int* x)
int Checkcapacity(pContact pc);//��鶯̬���ٵĿռ䣬��ǰ������
void Addcontact(pContact pc);
void Delcontact(pContact pc);
//ɾ��һ����Ա���͵�Ѱ��������
int Findcontact(pContact pc, char* name);//Ѱ�Ҹ��˵�����ͨѶ¼��λ��
void Searchcontact(pContact pc);//Ѱ��һ���ˣ�Ҳ��ʹ����������Ѱ��
void Modifycontact(pContact pc);
void Sortcontact(pContact pc);
void Showcontact(pContact pc);
//���Խ�ͨѶ¼����һ�����õĴ洢
void Loadcontact(pContact pc);
void Savecontact(pContact pc);