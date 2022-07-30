Arcade

(Aggregation)
- Note that the Game class controls the lifetime of the Context object. The state's constructor only 
takes a Context& rather than a shared_ptr<Context> to express the fact that it does not modify 
the lifetime or take ownership of the Context object. The Context ref will always be valid since it's
lifetime is bound by a Game object, which lives for the entire program.
(We take a ref rather than a pointer since we do not expect any null entries.)