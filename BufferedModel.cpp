
namespace Bdv {
	class BufferedModel {
	private:
		// int** vertices = new int* [sizeY];
		const int* vertices;
		const int* textures;
		const int* normals;
		const int* indexes;

	public:
		BufferedModel(int* vertices, int* textures, int* normals, int* indexes) {
			this->vertices = vertices;
			this->textures = textures;
			this->normals = normals;
			this->indexes = indexes;
		}
		BufferedModel(int* vertices, int* textures, int* indexes) {
			this->vertices = vertices;
			this->textures = textures;
			this->indexes = indexes;
		}
		~BufferedModel() {
			delete[] this->vertices;
			delete[] this->textures;
			delete[] this->normals;
			delete[] this->indexes;
		}

	};
}