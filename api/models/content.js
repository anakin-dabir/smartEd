import mongoose from 'mongoose';

const contentSchema = new mongoose.Schema(
    {
        type:String,
        detail:String,
        file:String,
        deadLine:String,
    },
    {
        timestamps: true,
        collection: 'Content'
    }
);
export default mongoose.model('Content', contentSchema);