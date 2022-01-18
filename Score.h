class Score
    {
        private:
            const int MaxLives = 3;
            int _points;
            int _lives;
        public:
            bool IsPlayerStillAlive() const { return _lives > 0; }

            Score();
            Score operator++();
            Score operator--();
            void Show();
    };