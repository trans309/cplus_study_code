#include "menu_system.h"
#include "worker.h"

void menu_system::menu()
{
    cout<<"******************************"<<endl;
    cout<<"*****欢迎使用职工管理系统*****"<<endl;
    cout<<"*****  1、 增加职工信息  *****"<<endl;
    cout<<"*****  2、 显示职工信息  *****"<<endl;
    cout<<"*****  3、 删除离职职工  *****"<<endl;
    cout<<"*****  4、 修改职工信息  *****"<<endl;
    cout<<"*****  5、 查找职工信息  *****"<<endl;
    cout<<"*****  6、 按早编号排序  *****"<<endl;
    cout<<"*****  7、 清空所有文档  *****"<<endl;
    cout<<"*****  0、 退出管理系统  *****"<<endl;
    cout<<"******************************"<<endl;
}

void menu_system::add_worker()
{
    int num;
    cout<<"请输入添加职工数："<<endl;
    cin>>num;

    //判断输入人数
    if(num>0)
    {
        //申请新空间
        worker **newspace=new worker*[this->worker_num+num];
        //若有元素,进行数据拷贝
        if(this->worker_arr!=NULL)
        {

            int i=0;
            for(;i<this->worker_num;i++)
            {
                newspace[i]=this->worker_arr[i];
            }
        }

        //循环添加
        int j=0;
        for(;j<num;j++)
        {
            int post;
            string name,id;

            cout<<"请输入职工编号:";
            cin>>id;
            cout<<"请输入职工姓名:";
            cin>>name;
            cout<<"1、员工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cout<<"请输入职工职位:"<<endl;
            cin>>post;

            //根据职位申请新空间（元素）
            switch(post)
            {
            case 1:
                newspace[worker_num+j]=new employee(id,name);cout<<"添加成功！"<<endl<<endl;
                break;
            case 2:
                newspace[worker_num+j]=new manage(id,name);cout<<"添加成功！"<<endl<<endl;
                break;
            case 3:
                newspace[worker_num+j]=new boss(id,name);cout<<"添加成功！"<<endl<<endl;
                break;
            default:
                cout<<"输入错误，重新添加\n"<<endl;
                j--;
                break;
            }
        }

        //释放老空间，链接新空间
        delete[] this->worker_arr;
        this->worker_arr=newspace;

        //更新职工人数
        this->worker_num+=num;
    }

    //错误输入添加人数
    else
    {
        cout<<"输入错误,退出添加\n"<<endl;
    }
}

void menu_system::show_worker()
{
    int i=0;
    if(this->worker_num>0)
    {
        for(;i<this->worker_num;i++)
        {
            this->worker_arr[i]->showInfo();
        }
    }
    else
    {
        cout<<"无职工信息！"<<"\n"<<"请进行添加！！\n"<<endl;
    }
}
