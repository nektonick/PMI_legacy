template <class ValueType>
class VectorStack : public MyVector<ValueType>, 
virtual public StackImplementation<ValueType>
{
public:
    //конструктор
    VectorStack();
    //конструктор копированием
    VectorStack(const VectorStack& copyVec);
    VectorStack& operator=(const VectorStack& copyVec);
    // Конструктор копирования присваиванием
    VectorStack(VectorStack&& moveVec) noexcept;
    VectorStack& operator=(VectorStack&& moveVec) noexcept;
    // добавление в конец
    void push(const ValueType& value) override;
    // удаление с хвоста
    void pop() override;
    // посмотреть элемент в хвосте
    const ValueType& top() const override;
    // проверка на пустоту
    bool isEmpty() const override;
    // размер
    size_t size() const override;
    // деструктор
    ~VectorStack();

};