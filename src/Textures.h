class Textures {
    public:
        static sf::Texture *textures;
        static sf::Texture getTexture(int i);
        static void init();
        static sf::Texture * createTextures();
};
