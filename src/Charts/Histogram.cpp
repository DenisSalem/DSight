#include "Histogram.hpp"
#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/DSightBaseException.hpp"

namespace DSight {
	Histogram::SetPair(std::vector<std::pair<float, float>> * pair_values_frequencies) {
		m_pair_values_frequencies = new std::vector<std::pair<float, float>>(pair_values_frequencies);
	}
	
	Histogram::SetPair(std::vector<float> * values, std::vector<float> * frequencies) {
		if (values.size() != frequencies.size()) {
			throw DSight::DSightBaseException("Mismatch between parameters lenght.", DSIGHT_MISMATCH_BETWEEN_PARAMS_LENGHT);
		}
		m_pair_values_frequencies = new std::vector<std::pair<float, float>>();
	}
	
	Histogram::~Histogram() {
		delete m_pair_values_frequencies;
	}
}
