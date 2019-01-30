#include "Histogram.hpp"
#include "../Exceptions/ExceptionCodes.hpp"
#include "../Exceptions/BaseException.hpp"
#include "../Exceptions/ExceptionMessages.hpp"
#include "../Contexts/ContextHandler.hpp"

namespace DSight {
	Histogram::Histogram() : m_pair_values_frequencies(NULL) {}
	
	void Histogram::SetPair(std::vector<std::pair<float, float>> * pair_values_frequencies) {
		delete m_pair_values_frequencies;
		m_pair_values_frequencies = new std::vector<std::pair<float, float>>(*pair_values_frequencies);
	}
	
	void Histogram::SetPair(std::vector<float> * values, std::vector<float> * frequencies) {
		delete m_pair_values_frequencies;
		if (values->size() != frequencies->size()) {
			throw DSight::BaseException(DSIGHT_MSG_MISMATCH_BETWEEN_PARAMS_LENGHT, DSight::ExceptionCode::MISMATCH_BETWEEN_PARAMS_LENGHT);
		}
		m_pair_values_frequencies = new std::vector<std::pair<float, float>>();
		for (unsigned int i = 0; i < values->size(); i++) {
			m_pair_values_frequencies->push_back(
				std::pair<float, float>(values->at(i), frequencies->at(i))
			);
		}
	}
	
	void Histogram::Draw() {
		ContextHandler::Draw();
	}
	
	Histogram::~Histogram() {
		delete m_pair_values_frequencies;
	}
}
