#ifndef INCLUDE_QUADLIST_H
#define INCLUDE_QUADLIST_H

namespace mydatastructure {

template <typename T> class QuadList {
public:
	QuadList() { Init(); }
	~QuadList() { Clear(); delete _header; delete _trailer; }

	/* read only interface */
	Rank Size() { return _size; }
	bool Empty() const { return _size <=0; }
	QListNodePosi(T) First() const { return _header->_succ; }
	QListNodePosi(T) Last() const { return _trailer->_pred; }
	bool Valid(QListNodePosi(T) p) { 
		return p && (_trailer != p) && (_header != p)
	}

	/* writable interface */
	T Remove(QListNodePosi(T) p);
	QListNodePosi(T) InsertAfterAbove(const T &e,
		QListNodePosi(T) p, QListNodePosi(T) b = nullptr);
	
	void Traverse(void(*) (T&));
	template <typename VST> void Traverse(VST&);
	
protected:
	void	Init();
	int		Clear();
	
private:
	int _size;
	QListNodePosi(T) _header;
	QListNodePosi(T) _trailer;

};	/* class QuadList */

}  /* namespace mydatastructure */
#endif
