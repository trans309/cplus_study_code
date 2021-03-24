#include "head.h"

class CPU
{
public:

    virtual void Calculate()=0;
    virtual ~CPU(){}
};

class GPU
{
public:

    virtual void GraphicsProcessing()=0;
    virtual ~GPU(){}
};

class ROM
{
public:

    virtual void Memery()=0;
    virtual ~ROM(){}
};

class ORG_computer
{
public:
    ORG_computer(CPU* get_cpu,GPU* get_gpu,ROM* get_rom)
    {
        cpu=get_cpu;
        gpu=get_gpu;
        rom=get_rom;
    }

    //��װ����
    void assemble()
    {
        cpu->Calculate();
        gpu->GraphicsProcessing();
        rom->Memery();
    }

    //����
    ~ORG_computer()
    {
        if(cpu!=NULL)
        {
            delete cpu;
            cpu=NULL;
            cout<<"CPU�����ɹ���"<<endl;
        }

        if(gpu!=NULL)
        {
            delete gpu;
            gpu=NULL;
            cout<<"GPU�����ɹ���"<<endl;
        }

        if(rom!=NULL)
        {
            delete rom;
            rom=NULL;
            cout<<"ROM�����ɹ���"<<endl;
            cout<<"-------------"<<endl;
        }
    }



private:
    CPU* cpu;
    GPU* gpu;
    ROM* rom;
};


//intel���
class intelCPU:public CPU
{
    void Calculate()
    {
        cout<<"intel���㹦�ܼ��سɹ�"<<endl;
    }
};

class intelGPU:public GPU
{
    void GraphicsProcessing()
    {
        cout<<"intelͼ�δ��������سɹ�"<<endl;
    }
};

class intelROM:public ROM
{
    void Memery()
    {
        cout<<"intelӲ�̼��سɹ�"<<endl;
    }
};

//HP���
class HPCPU:public CPU
{
    void Calculate()
    {
        cout<<"HP���㹦�ܼ��سɹ�"<<endl;
    }
};

class HPGPU:public GPU
{
    void GraphicsProcessing()
    {
        cout<<"HPͼ�δ��������سɹ�"<<endl;
    }
};

class HPROM:public ROM
{
    void Memery()
    {
        cout<<"HPӲ�̼��سɹ�"<<endl;
    }
};


//HW���
class HWCPU:public CPU
{
    void Calculate()
    {
        cout<<"HW���㹦�ܼ��سɹ�"<<endl;
    }
};

class HWGPU:public GPU
{
    void GraphicsProcessing()
    {
        cout<<"HWͼ�δ��������سɹ�"<<endl;
    }
};

class HWROM:public ROM
{
    void Memery()
    {
        cout<<"HWӲ�̼��سɹ�"<<endl;
    }
};



void ATC_test()
{
    //�������
    CPU* cpu=new intelCPU;
    GPU* gpu=new HPGPU;
    ROM* rom=new HWROM;

    //��װ����
    ORG_computer* computer1=new ORG_computer(cpu,gpu,rom);
    computer1->assemble();
    delete computer1;

    ORG_computer* computer2=new ORG_computer((CPU*)new HWCPU,(GPU*)new intelGPU,(ROM*)new HPGPU);
    computer2->assemble();
    delete computer2;
}
