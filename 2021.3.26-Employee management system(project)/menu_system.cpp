#include "menu_system.h"
#include "worker.h"

//打印菜单
void menu_system::menu()
{
    cout<<"******************************"<<endl;
    cout<<"*****欢迎使用职工管理系统*****"<<endl;
    cout<<"*****  1、 增加职工信息  *****"<<endl;
    cout<<"*****  2、 显示职工信息  *****"<<endl;
    cout<<"*****  3、 删除离职职工  *****"<<endl;
    cout<<"*****  4、 修改职工信息  *****"<<endl;
    cout<<"*****  5、 查找职工信息  *****"<<endl;
    cout<<"*****  6、 排序职工信息  *****"<<endl;
    cout<<"*****  7、 清空所有信息  *****"<<endl;
    cout<<"*****  0、 退出管理系统  *****"<<endl;
    cout<<"******************************"<<endl;
}



//构造--初始化文件人数
void menu_system::init_num()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int num=0;
    string m_id;
    string m_name;
    int m_p_id;

    //每读取一行，人数num+1
    while(ifs>>m_id&&ifs>>m_name&&ifs>>m_p_id)//ifs>>  ----  流模式读取，每遇到“空格、换行、文件结束”，停止读取
    {
        num++;
    }

    //初始化人数
    this->worker_num=num;

//    //测试
//    cout<<"共导入"<<num<<"名职工"<<endl;
    ifs.close();
}

//构造--导入文件内容，指针指向文件内容
void menu_system::init_worker()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    worker** new_worker_arr=new worker*[this->worker_num];

        string m_id;
        string m_name;
        int m_p_id;
        int i=0;

        while(ifs>>m_id&&ifs>>m_name&&ifs>>m_p_id)
        {
            if(m_p_id==1)
            {
                new_worker_arr[i]=new employee(m_id,m_name,m_p_id);
            }
            else if(m_p_id==2)
            {
                new_worker_arr[i]=new manage(m_id,m_name,m_p_id);
            }
            else if(m_p_id==3)
            {
                new_worker_arr[i]=new boss(m_id,m_name,m_p_id);
            }
            i++;
        }

    //释放旧空间
    delete[] this->worker_arr;
    this->worker_arr=NULL;

    //链接新空间
    this->worker_arr=new_worker_arr;

//    //测试，打印员工
//    this->show_worker();

    this->FileExists=true;

    ifs.close();
}








//基本功能函数


//添加职工
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
                newspace[worker_num+j]=new employee(id,name,post);cout<<"添加成功！"<<endl<<endl;
                break;
            case 2:
                newspace[worker_num+j]=new manage(id,name,post);cout<<"添加成功！"<<endl<<endl;
                break;
            case 3:
                newspace[worker_num+j]=new boss(id,name,post);cout<<"添加成功！"<<endl<<endl;
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

        //保存文件
        this->save_worker();
        this->FileExists=true;
        cout<<"成功添加"<<num<<"名职工\n"<<endl;
    }

    //错误输入添加人数
    else
    {
        cout<<"输入错误,退出添加\n"<<endl;
    }
}

//删除离职职工
void menu_system::delete_worker()
{
    string input;
    cout<<"输入要删除离职职工编号或姓名：";
    cin>>input;

    int i=this->find_worker(input);

    //未查到职工
    if(i==-1)
    {
        cout<<"无此人信息，请添加\n"<<endl;
        return;
    }

    //确认信息
    string ch;
    cout<<"确认删除此人？（y/n）"<<endl;
    cin>>ch;

    //确认删除
    if(ch=="y")
    {
        //被职工信息被后续信息覆盖
        for(;i<this->worker_num-1;i++)
        {
            this->worker_arr[i]=this->worker_arr[i+1];
        }

        //职工人数-1
        this->worker_num--;

        //如果删除后人数为0，则将flag设置为假--即文件无内容
        if(this->worker_num==0)
        {
            this->FileExists=false;
        }

        //保存文件
        this->save_worker();
        cout<<"删除成功！！"<<endl;
        return;
    }

    //取消删除
    cout<<"取消删除！！\n"<<endl;
}

//显示（打印）系统职工
void menu_system::show_worker()
{
    int i=0;
    if(this->worker_num>0 && this->FileExists==true)//两个条件意思一样,任选其一即可
    {
        for(;i<this->worker_num;i++)
        {
            this->worker_arr[i]->showInfo();
        }
    }
    else
    {
        cout<<"\n无职工信息！"<<"\n"<<"请进行添加！！\n"<<endl;
    }
}

//查找职工
void menu_system::search_worker()
{
    string input;
    cout<<"输入要查找职工编号或姓名：";
    cin>>input;

    //find_worker函数若查找到则 进行打印 并 返回下标
    //未找到 不打印 并 返回-1
    int i=this->find_worker(input);

    if(i==-1)
    {
        cout<<"无此人信息，请添加\n"<<endl;
        return;
    }
}

//修改员工信息
void menu_system::modify_worker()
{
    string input;
    cout<<"输入要修改职工编号或姓名：";
    cin>>input;

    //find_worker函数若查找到则 进行打印 并 返回下标
    //未找到 不打印 并 返回-1
    int i=this->find_worker(input);

    if(i==-1)
    {
        cout<<"无此人信息，请添加\n"<<endl;
        return;
    }

    //只有选择正确才能退出循环
    while(1)
    {
        string choise;
        cout<<"1、职工编号\n"<<"2、职工姓名\n"<<"3、职工职位"<<endl;
        cout<<"请选择修改的项目：";
        cin>>choise;

        if(choise=="1"||choise=="2"||choise=="3")
        {
            //修改职工编号
            if(choise=="1")
            {
                string mod;
                cout<<"将编号修改为：";
                cin>>mod;
                this->worker_arr[i]->id=mod;
                cout<<"修改成功！"<<endl;
            }

            //修改职工姓名
            else if(choise=="2")
            {
                string mod;
                cout<<"将姓名修改为：";
                cin>>mod;
                this->worker_arr[i]->name=mod;
                cout<<"修改成功！"<<endl;
            }

            //修改职工职位
            else if(choise=="3")
            {
                //修改职工职位涉及虚函数
                //需要重新在堆区开辟空间
                //利用函数实现
                this->mod_pid(this->worker_arr[i]);
            }

            //只有选择正确（1，2，3）
            //重新修改数据后
            //才询问是否继续修改
            cout<<"是否继续修改（y/n）"<<endl;
            cin>>choise;

            //‘y’继续，非‘y’退出修改
            if(choise!="y")
            {
                break;
            }

        }

        //修改的项目不为1，2，3时，提示输入错误，不退出循环
        else
        {
            cout<<"\n输入错误重新输入\n"<<endl;
        }
    }

    //打印修改后的信息
    cout<<"信息已修改为："<<endl;
    this->worker_arr[i]->showInfo();

    //保存文件
    this->save_worker();

}

//清空信息
void menu_system::clean_worker()
{
    //确认信息
    string c;
    cout<<"确定清空所有信息吗？（y/n）"<<endl;
    cin>>c;

    //确认清空
    if(c=="y")
    {
        //释放空间
        delete[] this->worker_arr;

        //初始化数组与人数
        this->worker_arr=NULL;
        this->worker_num=0;

        //初始化flag为空
        this->FileExists=false;

        //保存文件
        this->save_worker();
        cout<<"所有信息已清空！！\n"<<endl;
        return;
    }

    //取消清空
    cout<<"取消清空数据成功！！\n"<<endl;

}

//排序信息
//按名字，编号排序
//升降序排序
void menu_system::sort_worker()
{
    int choice1;
    cout<<"1、职员编号\n"<<"2、职员姓名"<<endl;
    cout<<"请选择排序项目：";
    cin>>choice1;
    if(choice1==1)
    {
        int choice2;
        cout<<"1、升序排序\n"<<"2、降序排序"<<endl;
        cout<<"请选择排序方式：";
        cin>>choice2;
        if(choice2==1)
        {
            //编号升序
            this->choose_sort(this->worker_arr,1,1);
        }
        else
        {
            //编号降序
            this->choose_sort(this->worker_arr,1,2);
        }
    }
    else if(choice1==2)
    {
        int choice2;
        cout<<"1、升序排序\n"<<"2、降序排序"<<endl;
        cout<<"请选择排序方式：";
        cin>>choice2;
        if(choice2==1)
        {
            //姓名升序
            this->choose_sort(this->worker_arr,2,1);
        }
        else
        {
            //姓名降序
            this->choose_sort(this->worker_arr,2,2);
        }
    }

        string c;
        cout<<"是否保存到文件中？（y/n）"<<endl;
        cin>>c;

        if(c=="y")
        {
            this->save_worker();
            cout<<"保存到文件成功"<<endl;
            return;
        }

        cout<<"已排序，未保存到文件中"<<endl;
}





//附加功能实现


//保存为文件
void menu_system::save_worker()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    int i=0;
    for(;i<this->worker_num;i++)
    {
        ofs<<this->worker_arr[i]->id<<"\t"
            <<this->worker_arr[i]->name<<"\t"
            <<this->worker_arr[i]->p_id<<endl;
    }
    ofs.close();
}

//按编号或者姓名查找信息
int menu_system::find_worker(string input)
{
    for(int i=0;i<this->worker_num;i++)
    {
        if(input==this->worker_arr[i]->name || input==this->worker_arr[i]->id)
        {
            cout<<endl;
            this->worker_arr[i]->showInfo();//打印职工信息
            cout<<endl;
            return i;//查找到职工则返回下标
        }
    }
    return -1;//查不到则返回-1
}

//修改职位
void menu_system::mod_pid(worker* &sor)//&--修改数组内数据
{
    int post;
    cout<<"\n1、员工"<<endl;
    cout<<"2、经理"<<endl;
    cout<<"3、老板"<<endl;
    cout<<"将职工职位修改为:";
    cin>>post;

    //根据职位申请新空间（元素）
    switch(post)
    {
    case 1:
        sor=new employee(sor->id,sor->name,post);cout<<"修改成功！"<<endl<<endl;
        break;
    case 2:
        sor=new manage(sor->id,sor->name,post);cout<<"修改成功！"<<endl<<endl;
        break;
    case 3:
        sor=new boss(sor->id,sor->name,post);cout<<"修改成功！"<<endl<<endl;
        break;
    default:
        break;
    }
}

//交换数据
void Swap(worker* &a,worker* &b)
{
    worker* temp=a;
    a=b;
    b=temp;
}

//选择排序
//way1 --- 项目
//way2 --- 方向
void menu_system::choose_sort(worker** &sor,int way1,int way2)
{
    //编号升序
    if(way1==1&&way2==1)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MIN=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->id<this->worker_arr[MIN]->id)//确定最小值下标
                {
                    MIN=j;
                }
            }
            Swap(this->worker_arr[MIN],this->worker_arr[i]);
        }
    }

    //编号降序
    else if(way1==1&&way2==2)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MAX=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->id>this->worker_arr[MAX]->id)//确定最大值下标
                {
                    MAX=j;
                }
            }
            Swap(this->worker_arr[MAX],this->worker_arr[i]);
        }
    }

    //姓名升序
    else if(way1==2&&way2==1)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MIN=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->name<this->worker_arr[MIN]->name)//确定最小值下标
                {
                    MIN=j;
                }
            }
            Swap(this->worker_arr[MIN],this->worker_arr[i]);
        }
    }

    //姓名降序
    else if(way1==2&&way2==2)
    {
        int i=0;
        for(;i<this->worker_num;i++)
        {
            int j=i;
            int MAX=i;

            for(;j<this->worker_num;j++)
            {
                if(this->worker_arr[j]->name>this->worker_arr[MAX]->name)//确定最大值下标
                {
                    MAX=j;
                }
            }
            Swap(this->worker_arr[MAX],this->worker_arr[i]);
        }
    }

}
