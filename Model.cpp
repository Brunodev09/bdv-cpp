namespace Bdv {
	class Model {
	public:
		int vaoId;
		int vertexCount;

		Model(const int vaoId, const int vertexCount) {
			this->vaoId = vaoId;
			this->vertexCount = vertexCount;
		}
	};
}