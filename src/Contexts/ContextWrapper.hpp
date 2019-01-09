namespace DSight {
	template <typename ContextClass> class ContextWrapper {
		public:
			ContextWrapper(ContextClass context);

		private:
			ContextClass m_context;
	};
}
