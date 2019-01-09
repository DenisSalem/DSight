#include "ContextWrapper.hpp"

namespace DSight {
	template <typename ContextClass> ContextWrapper<ContextClass>::ContextWrapper(ContextClass context) {
		m_context = context;	
	}
	
	template class ContextWrapper<int>;
}

