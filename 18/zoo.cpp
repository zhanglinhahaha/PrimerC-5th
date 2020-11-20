
class ZooAnimal{ };
class Endangered{ };
class Bear : public ZooAnimal { };
class Panda : public Bear, public Endangered { };

//显示地初始化所有基类
Panda::Panda(std::string name, bool onExhibit)
        : Bear(name, onExhibit, "Panda"),
          Endangered(Endangered::critical) { }
//隐式地使用Bear的默认构造函数初始化Bear子对象
Panda::Panda()
        : Endangered(Endangered::critical) { }
/*
如果一个类从它的多个基类中继承了相同的构造函数，则这个类必须为该
构造函数定义它自己的版本
*/

//虚基类
class Raccoon : public virtual ZooAnimal { /* ... */};
class Bear : virtual public ZooAnimal { /* ... */};
class Panda : public Bear, public Raccoon, public Endangered { };
//Panda通过Raccoon和Bear继承了ZooAnimal，因为虚继承，所以Panda中只有一个ZooAnimal基类部分

/*
构造函数顺序
间接虚基类
按照声明顺序直接虚基类
按照声明顺序非虚基类的间接基类
按照声明顺序非虚基类
最后是最底层的派生类
析构与构造函数顺序相反
*/
