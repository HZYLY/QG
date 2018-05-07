typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�



typedef struct  BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

enum Status{
	SUCCESS,
	ERROR
};


Status InitBiTree(BiTree T);
//�������������ն�����T
Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T
Status CreateBiTree(BiTree T, char* definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T

void print(BiTNode T); 
//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTNode T);
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTNode T);	//�������
Status PostOrderTraverse(BiTNode T);	//�������
Status LevelOrderTraverse(BiTNode T);	//�������
int Value(BiTNode T);			//������Ķ�������ֵ
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/
