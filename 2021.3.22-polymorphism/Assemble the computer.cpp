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

    //组装函数
    void assemble()
    {
        cpu->Calculate();
        gpu->GraphicsProcessing();
        rom->Memery();
    }

    //析构
    ~ORG_computer()
    {
        if(cpu!=NULL)
        {
            delete cpu;
            cpu=NULL;
            cout<<"CPU析构成功！"<<endl;
        }

        if(gpu!=NULL)
        {
            delete gpu;
            gpu=NULL;
            cout<<"GPU析构成功！"<<endl;
        }

        if(rom!=NULL)
        {
            delete rom;
            rom=NULL;
            cout<<"ROM析构成功！"<<endl;
            cout<<"-------------"<<endl;
        }
    }



private:
    CPU* cpu;
    GPU* gpu;
    ROM* rom;
};


//intel零件
class intelCPU:public CPU
{
    void Calculate()
    {
        cout<<"intel计算功能加载成功"<<endl;
    }
};

class intelGPU:public GPU
{
    void GraphicsProcessing()
    {
        cout<<"intel图形处理器加载成功"<<endl;
    }
};

class intelROM:public ROM
{
    void Memery()
    {
        cout<<"intel硬盘加载成功"<<endl;
    }
};

//HP零件
class HPCPU:public CPU
{
    void Calculate()
    {
        cout<<"HP计算功能加载成功"<<endl;
    }
};

class HPGPU:public GPU
{
    void GraphicsProcessing()
    {
        cout<<"HP图形处理器加载成功"<<endl;
    }
};

class HPROM:public ROM
{
    void Memery()
    {
        cout<<"HP硬盘加载成功"<<endl;
    }
};


//HW零件
class HWCPU:public CPU
{
    void Calculate()
    {
        cout<<"HW计算功能加载成功"<<endl;
    }
};

class HWGPU:public GPU
{
    void GraphicsProcessing()
    {
        cout<<"HW图形处理器加载成功"<<endl;
    }
};

class HWROM:public ROM
{
    void Memery()
    {
        cout<<"HW硬盘加载成功"<<endl;
    }
};



void ATC_test()
{
    //生成零件
    CPU* cpu=new intelCPU;
    GPU* gpu=new HPGPU;
    ROM* rom=new HWROM;

    //组装电脑
    ORG_computer* computer1=new ORG_computer(cpu,gpu,rom);
    computer1->assemble();
    delete computer1;

    ORG_computer* computer2=new ORG_computer((CPU*)new HWCPU,(GPU*)new intelGPU,(ROM*)new HPGPU);
    computer2->assemble();
    delete computer2;
}
