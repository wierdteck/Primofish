import { useState } from "react";
import { Chessboard } from "react-chessboard";
import { Button } from "@/components/ui/button";

const getBitboardMoves = (piece, square) => {
  const FILES = "abcdefgh";
  const RANKS = "12345678";
  const fileIndex = FILES.indexOf(square[0]);
  const rankIndex = RANKS.indexOf(square[1]);
  let moves = new Set();

  if (piece === "N") { // Knight moves
    const offsets = [
      [-2, -1], [-2, 1], [2, -1], [2, 1],
      [-1, -2], [-1, 2], [1, -2], [1, 2]
    ];
    offsets.forEach(([df, dr]) => {
      const f = fileIndex + df, r = rankIndex + dr;
      if (f >= 0 && f < 8 && r >= 0 && r < 8)
        moves.add(FILES[f] + RANKS[r]);
    });
  }
  // Add other pieces like Bishop, Rook, Queen using Stockfish logic
  
  return moves;
};

export default function BitboardVisualizer() {
  const [piece, setPiece] = useState("N");
  const [position, setPosition] = useState({});
  const [highlighted, setHighlighted] = useState(new Set());

  const handleSquareClick = (square) => {
    setPosition({ [square]: piece });
    setHighlighted(getBitboardMoves(piece, square));
  };

  return (
    <div className="flex flex-col items-center p-4">
      <Chessboard
        position={position}
        onSquareClick={handleSquareClick}
        customSquareStyles={
          Object.fromEntries([...highlighted].map(sq => [sq, { backgroundColor: "rgba(0,255,0,0.5)" }]))
        }
      />
      <div className="flex gap-2 mt-4">
        {"NBRQK".split("").map(p => (
          <Button key={p} onClick={() => setPiece(p)} className={piece === p ? "bg-blue-500" : ""}>
            {p}
          </Button>
        ))}
      </div>
    </div>
  );
}
