#pragma once

#include <iostream>

using namespace std;

#include <cstdlib>
#include "worker.h"
#include <fstream>
#include <string>

#define FILENAME "The worker list.data"

class menu_system
{
public:
    //基本系统功能
    void menu();
    void add_worker();
    void delete_worker();
    void show_worker();
    void search_worker();
    void clean_worker();
    void modify_worker();
    void sort_worker();

    //附加系统功能
    void save_worker();
    int find_worker(string);
    void mod_pid(worker* &sor);//修改职位
    void choose_sort(worker** &sor,int way1,int way2);



    //基本变量
    int worker_num;//职工人数
    worker** worker_arr;//保存职工数组
    bool FileExists;//判断文件存在且有数据---flag


    //构造--有文件时初始化人数
    void init_num();
    //构造--有人数后将文件内容导入缓冲区
    void init_worker();

    //构造
    menu_system()
    {
        ifstream ifs;
        ifs.open(FILENAME,ios::in);

        //1、无文件，无内容
        if(!ifs.is_open())
        {
            //测试
//            cout<<"文件不存在！！"<<endl;

            //初始化
            worker_num=0;
            worker_arr=NULL;
            FileExists=false;
            ifs.close();
            return;
        }

        //2、有文件，无内容
        char ch;
        ifs>>ch;//读取最后EOF标识符后，文件处于（返回？）结束状态**此行不可删
        if(ifs.eof())
        {
            //测试
//            cout<<"文件无内容！！"<<endl;

            //初始化
            worker_num=0;
            worker_arr=NULL;
            FileExists=false;
            ifs.close();
            return;
        }

        //3、有文件，有内容

        init_num();//初始化人数
        init_worker();//初始化员工
    }
    //析构
    ~menu_system()
    {
        if(worker_arr!=NULL)
        {
            delete[] worker_arr;
            this->worker_arr=NULL;
        }
    }
};
