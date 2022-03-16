#pragma once
using namespace std;

template <typename T1, typename T2>
class Base {
protected:
	T1 value1;
	T2 value2;
public:
	Base() {}; //конструктор по умолчанию

	Base(T1 one, T2 two) : value1(one), value2(two) {}

	friend ostream &operator << (ostream &stream, const Base<T1, T2>& gg) {
		stream << gg.value1 << gg.value2;
		return stream;
	}
};

template <typename T1, typename T2, typename T3, typename T4>
class Child1 : public Base<T1, T2> {
protected:
	T3 value3;
	T4 value4;
public:
	Child1() : Base <T1, T2>() {} //конструктор по умолчанию

	Child1(T1 one, T2 two, T3 thee, T4 four) : Base<T1, T2>(one, two), 
		value3(thee), value4(four) {} 
	
	friend ostream &operator << (ostream &stream, const Child1<T1, T2, T3, T4>& gg) {
		stream << gg.value1 << gg.value2 << gg.value3 << gg.value4;
		return stream;
	}
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child1<T1, T2, T3, T4> {
private:
	T5 value5;
	T6 value6;
public:
	Child2() : Child1<T1, T2, T3, T4>() {} //конструктор по умолчанию

	Child2(int one, int two, int three, int four, int five, int six) : Child1<T1, T2, T3, T4>(one, two, three, four), 
		value5(five), value6(six) {}

	friend ostream &operator << (ostream &stream, const Child2<T1, T2, T3, T4, T5, T6>& gg) {
		stream << gg.value1 << gg.value2 << gg.value3 << gg.value4 << gg.value5 << gg.value6;
		return stream;
	}
};