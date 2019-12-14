#pragma once
template<typename T>
class SafePointer {
public:
	SafePointer(T* p = nullptr) :ptr(p) {
	}

	~SafePointer() {
		SafeRelease();
	}

	void SafeRelease() {
		if(ptr!=nullptr) {
			ptr->Release();
		}
	}

	T*& operator->() {
		return ptr;
	}

	T** operator&() {
		return &ptr;
	}

	operator T*&(){
		return ptr;
	}
private:
	T* ptr;
};
