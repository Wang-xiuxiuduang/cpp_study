# 智能指针
需要头文件：**#include\<memory\>**
## 分类
1. **std::shared_ptr**
    - std::shared_ptr\<int\> pointer = std::make_shared\<int\>(10);
    - int* p = pointer.get();
    - int use_count = pointer.use_count();
    - pointer.reset();
2. **std::unique_ptr**
    - std::unique_ptr\<Student\> pointer(new Student());
    - std::unique_ptr\<Student\> pointer(new std::unique_ptr<Student>::element_type())
    - std::unique_ptr\<Student\> pointer_2(std::move(pointer));
    - pointer = std::move(pointer_2);
3. **std::weak_ptr**
    -

