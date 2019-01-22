#include "Chart.hpp"

namespace DSight {
	void Chart::SetRefreshDataCallback(void (*refresh_data_callback)(Chart *, void *)) {
		m_refresh_data_callback = refresh_data_callback;
	}
}
