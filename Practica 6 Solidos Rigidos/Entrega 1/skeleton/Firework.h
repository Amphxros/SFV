
#include "Particle.h"
#include <vector>

enum Type{SPHERE, SPARK, ASPERSOR, NONE}; //None es equivalente a undefined, ademas sirve para determinar el nº de tipos disponibles
class Firework :
	public Particle {
public:

	struct Payload {
		Payload(unsigned type, unsigned count, Vector4 
		
		
		);
		void integrate(float t);
		void explode();

		unsigned payloadType_;
		unsigned payloadCount_;
		Vector4 color;
		std::vector<Particle*> mParticles_;
	};

	struct FireWorkRule {
		unsigned ruleType;
		float minAge_, maxAge_;
		Vector3 minSpeed_, maxSpeed_;
		float damping_;
		std::vector<Payload*> mPayloads_;

		void set(unsigned type, float minAge, float maxAge, Vector3 minSpeed, Vector3 maxSpeed);
		void create(Firework* firework, const Firework* parent = NULL)	const;
	};

	int rule_;
	unsigned fireWorkType;
	FireWorkRule** rules = new FireWorkRule*[Type::NONE];
	Firework(Vector3 pos, Vector3 vel, Vector4 color, int rule, int type, int count);
	virtual ~Firework();

	void initFireworkRules(int type, int count);

	void integrate(float t);
	inline bool isActive() { return fireWorkType!=Type::NONE; }
	void setInactive();
};